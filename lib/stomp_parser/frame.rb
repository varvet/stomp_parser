require "stomp_parser/ruby_frame"

case RUBY_ENGINE
when "ruby", "rbx"
  require "stomp_parser/c_frame"
end

module StompParser
  Frame = RubyFrame
end
