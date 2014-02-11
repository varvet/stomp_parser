require "stomp_parser/version"
require "stomp_parser/error"
require "stomp_parser/frame"
require "stomp_parser/ruby_parser"

case RUBY_ENGINE
when "ruby", "rbx"
  require "stomp_parser/c_parser"
when "jruby"
  require "stomp_parser/java_parser"
end

module StompParser
  Parser = if defined?(CParser)
    CParser
  elsif defined?(JavaParser)
    JavaParser
  else
    RubyParser
  end

  @max_frame_size = 1024 * 10 # 10KB

  class << self
    attr_accessor :max_frame_size

    # Create a parse error from a string chunk and an index.
    #
    # @api private
    # @param [String] chunk
    # @param [Integer] index
    # @return [ParseError]
    def build_parse_error(chunk, index)
      ctx = 7
      min = [0, index - ctx].max
      len = ctx + 1 + ctx
      context = chunk.byteslice(min, len).force_encoding("BINARY")

      idx = index - min
      chr = context[idx]
      context[idx] = " -->#{chr}<-- "

      ParseError.new("unexpected #{chr} in chunk (#{context.inspect})")
    end
  end
end
