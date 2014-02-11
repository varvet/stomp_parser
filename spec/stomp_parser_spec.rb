describe StompParser do
  specify { defined?(StompParser::VERSION).should be_true }

  describe ".max_message_size" do
    it "has a sane default value" do
      StompParser.max_message_size.should be_a(Fixnum)
    end
  end
end
