describe StompParser do
  specify { defined?(StompParser::VERSION).should be_true }
  specify { defined?(StompParser::Frame).should be_true }
  specify { defined?(StompParser::Parser).should be_true }

  describe ".max_frame_size" do
    it "has a sane default value" do
      StompParser.max_frame_size.should be_a(Fixnum)
    end
  end
end
