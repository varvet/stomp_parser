describe StompParser::Frame do
  describe "#content_length" do
    it "returns content length if available" do
      frame = StompParser::Frame.new("CONNECT", { "content-length" => "1337" }, nil)
      frame.content_length.should eq 1337
    end

    it "returns nil if no content length defined" do
      frame = StompParser::Frame.new("CONNECT", nil)
      frame.content_length.should be_nil
    end

    it "raises an error if invalid content length defined" do
      frame = StompParser::Frame.new("CONNECT", { "content-length" => "LAWL" }, nil)
      expect { frame.content_length }.to raise_error(StompParser::Error, /invalid content length "LAWL"/)
    end
  end

  describe "#to_str" do
    specify "frame with command only" do
      frame = StompParser::Frame.new("CONNECT", nil)
      frame.to_str.should eq "CONNECT\ncontent-length:0\n\n\x00"
    end

    specify "frame with with headers" do
      frame = StompParser::Frame.new("CONNECT", { "moo" => "cow", "boo" => "hoo" }, nil)
      frame.to_str.should eq "CONNECT\nmoo:cow\nboo:hoo\ncontent-length:0\n\n\x00"
    end

    specify "frame with with body" do
      frame = StompParser::Frame.new("CONNECT", "this is a body")
      frame.to_str.should eq "CONNECT\ncontent-length:14\n\nthis is a body\x00"
    end

    specify "frame with escapeable characters in headers" do
      frame = StompParser::Frame.new("CONNECT", { "k\\\n\r:" => "v\\\n\r:" }, nil)
      frame.to_str.should eq "CONNECT\nk\\\\\\n\\r\\c:v\\\\\\n\\r\\c\ncontent-length:0\n\n\x00"
    end

    specify "frame with binary body" do
      frame = StompParser::Frame.new("CONNECT", "\x00ab\x00")
      frame.to_str.should eq "CONNECT\ncontent-length:4\n\n\x00ab\x00\x00"
    end

    specify "overrides user-specified content-length" do
      frame = StompParser::Frame.new("CONNECT", { "content-length" => "10" }, "\x00ab\x00")
      frame.to_str.should eq "CONNECT\ncontent-length:4\n\n\x00ab\x00\x00"
    end
  end
end
