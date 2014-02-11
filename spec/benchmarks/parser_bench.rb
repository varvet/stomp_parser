require_relative "../bench_helper"

def parse_one(parser, data)
  frame = nil
  parser.parse(data) { |m| frame = m }
  frame
end

%w[CParser JavaParser RubyParser].each do |parser|
  parser = begin
    StompParser.const_get(parser)
  rescue NameError
    next
  end

  describe "#{parser}: minimal" do |bench|
    bench.setup do
      @parser = parser.new
      @frame = "CONNECT\n\n\x00"
    end

    bench.code { parse_one(@parser, @frame) }
  end

  describe "#{parser}: headers and small body" do |bench|
    bench.setup do
      @parser = parser.new
      @frame = "CONNECT\ncontent-length:4\n\nbody\x00"
    end

    bench.code { parse_one(@parser, @frame) }
  end

  describe "#{parser}: headers and large body" do |bench|
    bench.setup do
      @parser = parser.new
      large_body = ("b" * (StompParser.max_frame_size - 50)) # make room for headers
      @frame = "CONNECT\ncontent-length:#{large_body.bytesize}\n\n#{large_body}\x00"
    end

    bench.code { parse_one(@parser, @frame) }
  end
end
