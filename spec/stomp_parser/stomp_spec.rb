describe StompParser::Stomp do
  describe ".max_message_size" do
    it "has a sane default value" do
      StompParser::Stomp.max_message_size.should be_a(Fixnum)
    end
  end
end
