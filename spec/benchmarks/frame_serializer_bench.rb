require_relative "../bench_helper"

describe "Frame#to_str minimal" do |bench|
  bench.setup do
    @frame = StompParser::Frame.new("CONNECT", nil)
  end

  bench.code { @frame.to_str }

  bench.assert do |frame_str|
    frame_str == "CONNECT\ncontent-length:0\n\n\x00"
  end
end

describe "Frame#to_str with header" do |bench|
  bench.setup do
    @frame = StompParser::Frame.new("CONNECT", { "heart-beat" => "0,0" }, nil)
  end

  bench.code { @frame.to_str }

  bench.assert do |frame_str|
    frame_str == "CONNECT\nheart-beat:0,0\ncontent-length:0\n\n\x00"
  end
end

describe "Frame#to_str with headers and small body" do |bench|
  bench.setup do
    @frame = StompParser::Frame.new("CONNECT", { "some" => "header" }, "body")
  end

  bench.code { @frame.to_str }

  bench.assert do |frame_str|
    frame_str == "CONNECT\nsome:header\ncontent-length:4\n\nbody\x00"
  end
end

describe "Frame#to_str with headers and large body" do |bench|
  bench.setup do
    large_binary = "b\x00" * 2 # make room for headers
    @frame = StompParser::Frame.new("CONNECT", { "some" => "header" }, large_binary)
  end

  bench.code { @frame.to_str }

  bench.assert do |frame_str|
    frame_str == "CONNECT\nsome:header\ncontent-length:#{@frame.body.bytesize}\n\n#{@frame.body}\x00"
  end
end
