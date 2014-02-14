require_relative "../bench_helper"

describe "Frame#content_encoding without encoding" do |bench|
  bench.setup { @frame = StompParser::Frame.new("CONNECT") }
  bench.code { @frame.content_encoding }
  bench.assert { |encoding| encoding == Encoding::BINARY }
end

describe "Frame#content_encoding with implicit encoding" do |bench|
  bench.setup { @frame = StompParser::Frame.new("CONNECT", { "content-type" => "text/plain" }) }
  bench.code { @frame.content_encoding }
  bench.assert { |encoding| encoding == Encoding::UTF_8 }
end

describe "Frame#content_encoding with explicit encoding" do |bench|
  bench.setup { @frame = StompParser::Frame.new("CONNECT", { "content-type" => "text/plain;charset=ISO-8859-1" }) }
  bench.code { @frame.content_encoding }
  bench.assert { |encoding| encoding == Encoding::ISO_8859_1 }
end
