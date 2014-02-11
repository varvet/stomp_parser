%%{
  machine frame;

  getkey (chunk.getbyte(p) ^ 128) - 128;

  action mark {
    mark = p
  }
  action mark_key {
    mark_key = chunk.byteslice(mark, p - mark)
    mark = nil
  }
  action mark_frame {
    mark_frame = Frame.new(nil, nil)
    mark_frame_size = 0
  }
  action check_frame_size {
    mark_frame_size += 1
    raise FrameSizeExceeded if mark_frame_size > max_frame_size
  }

  action write_command {
    mark_frame.write_command(chunk.byteslice(mark, p - mark))
    mark = nil
  }

  action write_header {
    mark_frame.write_header(mark_key, chunk.byteslice(mark, p - mark))
    mark_key = mark = nil
  }

  action write_body {
    mark_frame.write_body(chunk.byteslice(mark, p - mark))
    mark = nil
  }

  action finish_headers {
    mark_content_length = mark_frame.content_length
  }

  action consume_null {
    (p - mark) < mark_content_length if mark_content_length
  }

  action consume_octet {
    if mark_content_length
      (p - mark) < mark_content_length
    else
      true
    end
  }

  action finish_frame {
    yield mark_frame
    mark_frame = nil
  }

  include frame_common "parser_common.rl";
}%%

module StompParser
  class RubyParser
    class State
      def initialize
        @cs = RubyParser.start
        @chunk = nil
        @mark = nil
        @mark_key = nil
        @mark_frame = nil
        @mark_frame_size = nil
        @mark_content_length = nil
      end

      # You want documentation? HAHA.
      attr_accessor :chunk
      attr_accessor :cs
      attr_accessor :mark
      attr_accessor :mark_key
      attr_accessor :mark_frame
      attr_accessor :mark_frame_size
      attr_accessor :mark_content_length
    end

    # this manipulates the singleton class of our context,
    # so we do not want to run this code very often or we
    # bust our ruby method caching
    %% write data noprefix;

    # Parse a chunk of Stomp-formatted data into a Frame.
    #
    # @param [String] chunk
    # @param [State] state previous parser state, or nil for initial state
    # @param [Integer] max_frame_size
    # @yield [frame] yields each frame as it is parsed
    # @yieldparam frame [Frame]
    def self._parse(chunk, state, max_frame_size)
      chunk.force_encoding(Encoding::BINARY)

      if state.chunk
        p = state.chunk.bytesize
        chunk = state.chunk << chunk
      else
        p = 0
      end

      pe = chunk.bytesize # special

      cs = state.cs
      mark = state.mark
      mark_key = state.mark_key
      mark_frame = state.mark_frame
      mark_frame_size = state.mark_frame_size
      mark_content_length = state.mark_content_length

      %% write exec;

      if mark
        state.chunk = chunk
      else
        state.chunk = nil
      end

      state.cs = cs
      state.mark = mark
      state.mark_key = mark_key
      state.mark_frame = mark_frame
      state.mark_frame_size = mark_frame_size
      state.mark_content_length = mark_content_length

      if cs == RubyParser.error
        StompParser.build_parse_error(chunk, p)
      else
        nil
      end
    end

    def initialize(max_frame_size = StompParser.max_frame_size)
      @state = State.new
      @max_frame_size = Integer(max_frame_size)
    end

    # Parse a chunk.
    #
    # @param [String] chunk
    # @yield [frame]
    # @yieldparam [Frame] frame
    def parse(chunk)
      @error ||= self.class._parse(chunk, @state, @max_frame_size) do |frame|
        yield frame
      end

      raise @error if @error
    end
  end
end
