# StompParser

[![Build Status](https://travis-ci.org/stompede/stomp_parser.png?branch=master)](https://travis-ci.org/stompede/stomp_parser)
[![Dependency Status](https://gemnasium.com/stompede/stomp_parser.png)](https://gemnasium.com/stompede/stomp_parser)
[![Code Climate](https://codeclimate.com/github/stompede/stomp_parser.png)](https://codeclimate.com/github/stompede/stomp_parser)
[![Gem Version](https://badge.fury.io/rb/stomp_parser.png)](http://badge.fury.io/rb/stomp_parser)

Fast STOMP parser and serializer for Ruby with native extensions in C for MRI
and Rubinius and in Java for JRuby, as well as a pure Ruby parser.

## Parsing

``` ruby
parser = StompParser::Parser.new
parser.parse(chunk) do |frame|
  puts "We received #{frame.command} frame with #{frame.body} and headers #{frame.headers}!"
end
```

The chunks do not have to be complete STOMP frames. The callback will be called
whenever a complete frame has been parsed. Additionally, StompParser handles
escape sequences in headers and body encoding for you.

## Serializing

``` ruby
StompParser::Frame.new("SEND", { some: "header" }, "Hello").to_str
```

## Development

Development should be ez.

``` bash
git clone git@github.com:stompede/stomp_parser.git # git, http://git-scm.com/
cd stomp_parser
brew bundle # Homebrew, http://brew.sh/
bundle install # Bundler, http://bundler.io/
rake # compile state machine, run test suite
```

A few notes:

- Native dependencies are listed in the Brewfile.
- The stomp message parser is written in [Ragel](http://www.complang.org/ragel/), see [parser_common.rl](parser_common.rl).
- Graphviz is used to visualize the Ragel state machine.
- Most rake tasks will compile the state machine anew if needed.

## Contributing

1. Fork it on GitHub (<http://github.com/stompede/stomp_parser/fork>).
2. Create your feature branch (`git checkout -b my-new-feature`).
3. Follow the [Development](#development) instructions in this README.
4. Create your changes, please add tests.
5. Commit your changes (`git commit -am 'Add some feature'`).
6. Push to the branch (`git push origin my-new-feature`).
7. Create new pull request on GitHub.

## License

[MIT](MIT-LICENSE.txt)
