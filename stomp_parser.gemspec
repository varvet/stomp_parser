# coding: utf-8
lib = File.expand_path('../lib', __FILE__)
$LOAD_PATH.unshift(lib) unless $LOAD_PATH.include?(lib)
require 'stomp_parser/version'

Gem::Specification.new do |spec|
  spec.name          = "stomp_parser"
  spec.version       = StompParser::VERSION
  spec.authors       = ["Kim Burgestrand", "Jonas Nicklas"]
  spec.email         = ["kim@burgestrand.se", "jonas.nicklas@gmail.com"]
  spec.summary       = %q{STOMP frame parser.}
  spec.homepage      = "https://github.com/stompede/stomp_parser"
  spec.license       = "MIT"

  spec.files         = `git ls-files`.split($/)
  spec.files        += ["lib/stomp_parser/ruby_parser.rb"]
  spec.files        += ["ext/stomp_parser/c_parser.c"]
  spec.executables   = spec.files.grep(%r{^bin/}) { |f| File.basename(f) }
  spec.test_files    = spec.files.grep(%r{^(test|spec|features)/})
  spec.require_paths = ["lib"]
  spec.extensions    = %w[ext/stomp_parser/extconf.rb]

  spec.add_development_dependency "bundler"
  spec.add_development_dependency "rake"
  spec.add_development_dependency "rake-compiler"
  spec.add_development_dependency "rspec"
  spec.add_development_dependency "pry"
end
