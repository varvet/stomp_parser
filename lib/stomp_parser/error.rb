module StompParser
  class Error < StandardError
  end

  # Errors raised by the Parser.
  class ParseError < Error
  end

  # Raised when the Parser has reached the
  # limit for how large a Frame may be.
  #
  # Protects against malicious clients trying to
  # fill the available memory by sending very large
  # messages, for example by sending an unlimited
  # amount of headers.
  class FrameSizeExceeded < ParseError
  end
end
