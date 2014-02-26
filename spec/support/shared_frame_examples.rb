# encoding: UTF-8
RSpec.shared_examples_for "a stomp_parser frame" do
  let(:frame_klass) { described_class }

  describe "#initialize" do
    it "can be initialized without arguments" do
      frame = frame_klass.new
      frame.command.should eq("")
      frame.headers.should eq({})
      frame.body.should eq("")
    end

    it "can be initialized with only command" do
      frame = frame_klass.new("CONNECT")
      frame.command.should eq("CONNECT")
      frame.headers.should eq({})
      frame.body.should eq("")
    end

    it "can be initialized with only command and body" do
      frame = frame_klass.new("CONNECT", "this is body")
      frame.command.should eq("CONNECT")
      frame.headers.should eq({})
      frame.body.should eq("this is body")
    end

    it "can be initialized with only command and headers" do
      frame = frame_klass.new("CONNECT", { "header" => "value" })
      frame.command.should eq("CONNECT")
      frame.headers.should eq({ "header" => "value" })
      frame.body.should eq("")
    end

    it "can be initialized with command, headers, and body" do
      frame = frame_klass.new("CONNECT", { "header" => "value" }, "this is body")
      frame.command.should eq("CONNECT")
      frame.headers.should eq({ "header" => "value" })
      frame.body.should eq("this is body")
    end
  end

  describe "#[key]" do
    it "retrieves raw headers" do
      frame = frame_klass.new("CONNECT", { "content-length" => "LA\x00WL" })
      frame["content-length"].should eq("LA\x00WL")
    end
  end

  describe "#[key] = value" do
    it "sets raw headers without translation" do
      frame = frame_klass.new
      frame["some-value"] = ":he\x00lo:"
      frame.headers.should eq({ "some-value" => ":he\x00lo:" })
    end
  end

  describe "#content_length" do
    it "returns content length if available" do
      frame = frame_klass.new("CONNECT", { "content-length" => "1337" })
      frame.content_length.should eq 1337
    end

    it "returns nil if no content length defined" do
      frame = frame_klass.new("CONNECT")
      frame.content_length.should be_nil
    end

    it "raises an error if invalid content length defined" do
      frame = frame_klass.new("CONNECT", { "content-length" => "LAWL" })
      expect { frame.content_length }.to raise_error(StompParser::Error, /invalid content length "LAWL"/)
    end
  end

  describe "#content_encoding" do
    it "assumes binary when no content type is available" do
      frame = frame_klass.new
      frame.content_encoding.should eq Encoding::BINARY
    end

    it "raises an error when specifying special ruby encodings that do not exist" do
      with_internal_encoding nil do
        frame = frame_klass.new("CONNECT", { "content-type" => "text/plain;charset=internal" })
        expect { frame.content_encoding }.to raise_error(StompParser::InvalidEncodingError, /internal/)
      end
    end

    it "raises an error when specified charset does not exist in ruby" do
      frame = frame_klass.new("CONNECT", { "content-type" => "text/plain;charset=roflscale" })
      expect { frame.content_encoding }.to raise_error(StompParser::InvalidEncodingError, /roflscale/)
    end

    context "with text/ content type" do
      it "assumes UTF-8 when no charset is given" do
        frame = frame_klass.new("CONNECT", { "content-type" => "text/plain" })
        frame.content_encoding.should eq Encoding::UTF_8
      end

      it "respects charset when charset is given" do
        frame = frame_klass.new("CONNECT", { "content-type" => "text/plain;charset=ISO-8859-1" })
        frame.content_encoding.should eq Encoding::ISO_8859_1
      end
    end

    context "with specified content type" do
      it "assumes binary when no charset is given" do
        frame = frame_klass.new("CONNECT", { "content-type" => "application/octet-stream" })
        frame.content_encoding.should eq Encoding::BINARY
      end

      it "respects charset when charset is given" do
        frame = frame_klass.new("CONNECT", { "content-type" => "application/octet-stream;charset=ISO-8859-1" })
        frame.content_encoding.should eq Encoding::ISO_8859_1
      end
    end
  end

  describe "#to_str" do
    specify "frame with command only" do
      frame = frame_klass.new("CONNECT")
      frame.to_str.should eq "CONNECT\ncontent-length:0\n\n\x00"
    end

    specify "frame with with headers" do
      frame = frame_klass.new("CONNECT", { "moo" => "cow", "boo" => "hoo" })
      frame.to_str.should eq "CONNECT\nmoo:cow\nboo:hoo\ncontent-length:0\n\n\x00"
    end

    specify "frame with with binary headers" do
      frame = frame_klass.new("CONNECT", { "m\x00o" => "c\x00w" })
      frame.to_str.should eq "CONNECT\nm\x00o:c\x00w\ncontent-length:0\n\n\x00"
    end

    specify "frame with with body" do
      frame = frame_klass.new("CONNECT", "this is a body")
      frame.to_str.should eq "CONNECT\ncontent-length:14\n\nthis is a body\x00"
    end

    specify "frame with escapeable characters in headers" do
      frame = frame_klass.new("CONNECT", { "k\\\n\r:" => "v\\\n\r:" })
      frame.to_str.should eq "CONNECT\nk\\\\\\n\\r\\c:v\\\\\\n\\r\\c\ncontent-length:0\n\n\x00"
    end

    specify "frame with binary body" do
      frame = frame_klass.new("CONNECT", "\x00ab\x00")
      frame.to_str.should eq "CONNECT\ncontent-length:4\n\n\x00ab\x00\x00"
    end

    specify "overrides user-specified content-length" do
      frame = frame_klass.new("CONNECT", { "content-length" => "10" }, "\x00ab\x00")
      frame.to_str.should eq "CONNECT\ncontent-length:4\n\n\x00ab\x00\x00"
    end
  end
end
