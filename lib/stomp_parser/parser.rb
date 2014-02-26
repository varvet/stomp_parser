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
end
