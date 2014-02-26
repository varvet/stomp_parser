require "bundler/setup"
require "stomp_parser"
require "pry"
require "timeout"

require "support/shared_parser_examples"
require "support/shared_frame_examples"

module Helpers
  def with_internal_encoding(encoding)
    old_encoding = Encoding.default_internal
    Encoding.default_internal = encoding
    yield
  ensure
    Encoding.default_internal = old_encoding
  end
end

RSpec.configure do |config|
  config.include(Helpers)
end
