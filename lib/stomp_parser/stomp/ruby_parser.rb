
# line 1 "lib/stomp_parser/stomp/ruby_parser.rb.rl"

# line 59 "lib/stomp_parser/stomp/ruby_parser.rb.rl"


module StompParser
  module Stomp
    class RubyParser
      class State
        def initialize
          @cs = RubyParser.start
          @chunk = nil
          @mark = nil
          @mark_key = nil
          @mark_message = nil
          @mark_message_size = nil
          @mark_content_length = nil
        end

        # You want documentation? HAHA.
        attr_accessor :chunk
        attr_accessor :cs
        attr_accessor :mark
        attr_accessor :mark_key
        attr_accessor :mark_message
        attr_accessor :mark_message_size
        attr_accessor :mark_content_length
      end

      # this manipulates the singleton class of our context,
      # so we do not want to run this code very often or we
      # bust our ruby method caching
      
# line 36 "lib/stomp_parser/stomp/ruby_parser.rb"
class << self
	attr_accessor :_cond_keys
	private :_cond_keys, :_cond_keys=
end
self._cond_keys = [
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, -128, 127, -128, 127, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0
]

class << self
	attr_accessor :_cond_key_spans
	private :_cond_key_spans, :_cond_key_spans=
end
self._cond_key_spans = [
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 256, 256, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	
]

class << self
	attr_accessor :_cond_spaces
	private :_cond_spaces, :_cond_spaces=
end
self._cond_spaces = [
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	1, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	1, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	2, 2, 2, 2, 2, 2, 2, 2, 
	0
]

class << self
	attr_accessor :_cond_offsets
	private :_cond_offsets, :_cond_offsets=
end
self._cond_offsets = [
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 256, 
	512, 512, 512, 512, 512, 512, 512, 512, 
	512, 512, 512, 512, 512, 512, 512, 512, 
	512, 512, 512, 512, 512, 512, 512, 512, 
	512, 512, 512, 512, 512, 512, 512, 512, 
	512, 512, 512, 512, 512, 512, 512, 512, 
	512, 512, 512, 512, 512, 512, 512, 512, 
	512, 512, 512, 512, 512, 512, 512, 512
]

class << self
	attr_accessor :_trans_keys
	private :_trans_keys, :_trans_keys=
end
self._trans_keys = [
	0, 0, 10, 10, 66, 67, 
	79, 79, 82, 82, 84, 
	84, 10, 13, 10, 92, 
	10, 92, 10, 92, 10, 92, 
	10, 10, 92, 114, 92, 
	114, 256, 1151, 256, 1151, 
	10, 10, 75, 75, 69, 69, 
	71, 71, 73, 73, 78, 
	78, 79, 79, 77, 78, 
	77, 77, 73, 73, 78, 78, 
	69, 69, 67, 67, 84, 
	84, 10, 69, 68, 68, 
	73, 73, 83, 83, 67, 67, 
	79, 79, 78, 78, 78, 
	78, 69, 69, 67, 67, 
	82, 82, 82, 82, 79, 79, 
	82, 82, 69, 69, 83, 
	83, 83, 83, 65, 65, 
	71, 71, 69, 69, 65, 65, 
	67, 67, 69, 69, 67, 
	67, 69, 69, 73, 73, 
	80, 80, 69, 85, 78, 78, 
	79, 79, 77, 77, 80, 
	80, 66, 66, 83, 83, 
	67, 67, 82, 82, 73, 73, 
	66, 66, 78, 78, 83, 
	83, 85, 85, 10, 85, 
	0
]

class << self
	attr_accessor :_key_spans
	private :_key_spans, :_key_spans=
end
self._key_spans = [
	0, 1, 2, 1, 1, 1, 4, 83, 
	83, 83, 83, 1, 23, 23, 896, 896, 
	1, 1, 1, 1, 1, 1, 1, 2, 
	1, 1, 1, 1, 1, 1, 60, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 17, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 76
]

class << self
	attr_accessor :_index_offsets
	private :_index_offsets, :_index_offsets=
end
self._index_offsets = [
	0, 0, 2, 5, 7, 9, 11, 16, 
	100, 184, 268, 352, 354, 378, 402, 1299, 
	2196, 2198, 2200, 2202, 2204, 2206, 2208, 2210, 
	2213, 2215, 2217, 2219, 2221, 2223, 2225, 2286, 
	2288, 2290, 2292, 2294, 2296, 2298, 2300, 2302, 
	2304, 2306, 2308, 2310, 2312, 2314, 2316, 2318, 
	2320, 2322, 2324, 2326, 2328, 2330, 2332, 2334, 
	2336, 2338, 2356, 2358, 2360, 2362, 2364, 2366, 
	2368, 2370, 2372, 2374, 2376, 2378, 2380, 2382
]

class << self
	attr_accessor :_indicies
	private :_indicies, :_indicies=
end
self._indicies = [
	0, 1, 2, 3, 1, 4, 1, 5, 
	1, 6, 1, 7, 1, 1, 8, 1, 
	10, 9, 9, 11, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	1, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 9, 9, 9, 9, 9, 9, 
	9, 9, 12, 9, 1, 13, 13, 1, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 14, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 13, 13, 
	13, 13, 13, 13, 13, 13, 15, 13, 
	17, 16, 16, 18, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	1, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 16, 16, 16, 16, 16, 16, 
	16, 16, 19, 16, 21, 20, 20, 22, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 1, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 20, 20, 
	20, 20, 20, 20, 20, 20, 23, 20, 
	24, 1, 20, 1, 1, 1, 1, 1, 
	1, 20, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 20, 1, 1, 1, 
	20, 1, 13, 1, 1, 1, 1, 1, 
	1, 13, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 13, 1, 1, 1, 
	13, 1, 25, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 26, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 1, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 1, 25, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 26, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 1, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 26, 26, 26, 26, 26, 
	26, 26, 26, 1, 27, 1, 6, 1, 
	28, 1, 29, 1, 30, 1, 6, 1, 
	31, 1, 32, 33, 1, 34, 1, 5, 
	1, 35, 1, 36, 1, 37, 1, 38, 
	1, 7, 1, 1, 8, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 39, 1, 6, 1, 
	40, 1, 41, 1, 42, 1, 43, 1, 
	44, 1, 45, 1, 46, 1, 5, 1, 
	47, 1, 48, 1, 49, 1, 6, 1, 
	50, 1, 51, 1, 52, 1, 53, 1, 
	54, 1, 6, 1, 55, 1, 3, 1, 
	56, 1, 57, 1, 58, 1, 59, 1, 
	5, 1, 60, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 61, 62, 1, 39, 1, 63, 1, 
	64, 1, 6, 1, 65, 1, 66, 1, 
	67, 1, 68, 1, 69, 1, 54, 1, 
	70, 1, 71, 1, 62, 1, 0, 1, 
	1, 72, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 73, 74, 75, 
	76, 77, 1, 1, 1, 1, 1, 1, 
	1, 78, 79, 1, 1, 1, 80, 81, 
	1, 82, 1, 0
]

class << self
	attr_accessor :_trans_targs
	private :_trans_targs, :_trans_targs=
end
self._trans_targs = [
	71, 0, 3, 17, 4, 5, 6, 7, 
	11, 8, 14, 16, 13, 8, 9, 13, 
	10, 7, 11, 12, 10, 7, 11, 12, 
	7, 71, 15, 14, 19, 20, 21, 23, 
	24, 26, 25, 27, 28, 29, 30, 31, 
	33, 34, 35, 36, 37, 38, 39, 41, 
	42, 43, 45, 46, 47, 48, 49, 51, 
	53, 54, 55, 56, 58, 59, 62, 60, 
	61, 63, 64, 65, 66, 67, 69, 70, 
	1, 2, 18, 22, 32, 40, 44, 50, 
	52, 57, 68
]

class << self
	attr_accessor :_trans_actions
	private :_trans_actions, :_trans_actions=
end
self._trans_actions = [
	0, 0, 1, 1, 1, 1, 1, 2, 
	2, 3, 4, 4, 3, 1, 5, 1, 
	3, 6, 6, 3, 1, 7, 7, 1, 
	1, 9, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 1, 1, 1, 1, 1, 1, 1, 
	0, 10, 10, 10, 10, 10, 10, 10, 
	10, 10, 10
]

class << self
	attr_accessor :_from_state_actions
	private :_from_state_actions, :_from_state_actions=
end
self._from_state_actions = [
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 8, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 0, 0, 0
]

class << self
	attr_accessor :start
end
self.start = 71;
class << self
	attr_accessor :first_final
end
self.first_final = 71;
class << self
	attr_accessor :error
end
self.error = 0;

class << self
	attr_accessor :en_stream
end
self.en_stream = 71;


# line 89 "lib/stomp_parser/stomp/ruby_parser.rb.rl"

      # Parse a chunk of Stomp-formatted data into a Message.
      #
      # @param [String] chunk
      # @param [State] state previous parser state, or nil for initial state
      # @param [Integer] max_message_size
      # @yield [message] yields each message as it is parsed
      # @yieldparam message [Stomp::Message]
      def self._parse(chunk, state, max_message_size)
        chunk.force_encoding(Encoding::BINARY)

        if state.chunk
          p = state.chunk.bytesize
          chunk = state.chunk << chunk
        else
          p = 0
        end

        pe = chunk.bytesize # special

        cs = state.cs
        mark = state.mark
        mark_key = state.mark_key
        mark_message = state.mark_message
        mark_message_size = state.mark_message_size
        mark_content_length = state.mark_content_length

        
# line 650 "lib/stomp_parser/stomp/ruby_parser.rb"
begin
	testEof = false
	_slen, _trans, _keys, _inds, _cond, _conds, _widec, _acts, _nacts = nil
	_goto_level = 0
	_resume = 10
	_eof_trans = 15
	_again = 20
	_test_eof = 30
	_out = 40
	while true
	if _goto_level <= 0
	if p == pe
		_goto_level = _test_eof
		next
	end
	if cs == 0
		_goto_level = _out
		next
	end
	end
	if _goto_level <= _resume
	case _from_state_actions[cs] 
	when 8 then
# line 6 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark = p
  		end
# line 679 "lib/stomp_parser/stomp/ruby_parser.rb"
	end
	_widec = ( (chunk.getbyte(p) ^ 128) - 128)
	_keys = cs << 1
	_conds = _cond_offsets[cs]
	_slen = _cond_key_spans[cs]
	_cond = if ( _slen > 0 && 
		     _cond_keys[_keys] <= _widec &&
		     _widec <= _cond_keys[_keys + 1]
		   ) then 
			_cond_spaces[ _conds + _widec - _cond_keys[_keys] ]
		else
		       0
		end
	case _cond 
	when 1 then
		_widec = (128 + (( (chunk.getbyte(p) ^ 128) - 128) - -128))
		if ( 
# line 41 "lib/stomp_parser/stomp/ruby_parser.rb.rl"

    (p - mark) < mark_content_length if mark_content_length
   ) then 
			  _widec += 256
end
	when 2 then
		_widec = (640 + (( (chunk.getbyte(p) ^ 128) - 128) - -128))
		if ( 
# line 45 "lib/stomp_parser/stomp/ruby_parser.rb.rl"

    if mark_content_length
      (p - mark) < mark_content_length
    else
      true
    end
   ) then 
			  _widec += 256
end
	end # _cond switch 
	_keys = cs << 1
	_inds = _index_offsets[cs]
	_slen = _key_spans[cs]
	_trans = if (   _slen > 0 && 
			_trans_keys[_keys] <= _widec && 
			_widec <= _trans_keys[_keys + 1] 
		    ) then
			_indicies[ _inds + _widec - _trans_keys[_keys] ] 
		 else 
			_indicies[ _inds + _slen ]
		 end
	cs = _trans_targs[_trans]
	if _trans_actions[_trans] != 0
	case _trans_actions[_trans]
	when 1 then
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 3 then
# line 6 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark = p
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 5 then
# line 9 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_key = chunk.byteslice(mark, p - mark)
    mark = nil
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 2 then
# line 22 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message.write_command(chunk.byteslice(mark, p - mark))
    mark = nil
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 7 then
# line 27 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message.write_header(mark_key, chunk.byteslice(mark, p - mark))
    mark_key = mark = nil
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 4 then
# line 37 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_content_length = mark_message.content_length
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 6 then
# line 6 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark = p
  		end
# line 27 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message.write_header(mark_key, chunk.byteslice(mark, p - mark))
    mark_key = mark = nil
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 10 then
# line 13 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message = Stomp::Message.new(nil, nil)
    mark_message_size = 0
  		end
# line 6 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark = p
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
	when 9 then
# line 32 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message.write_body(chunk.byteslice(mark, p - mark))
    mark = nil
  		end
# line 53 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    yield mark_message
    mark_message = nil
  		end
# line 17 "lib/stomp_parser/stomp/ruby_parser.rb.rl"
		begin

    mark_message_size += 1
    raise MessageSizeExceeded if mark_message_size > max_message_size
  		end
# line 856 "lib/stomp_parser/stomp/ruby_parser.rb"
	end
	end
	end
	if _goto_level <= _again
	if cs == 0
		_goto_level = _out
		next
	end
	p += 1
	if p != pe
		_goto_level = _resume
		next
	end
	end
	if _goto_level <= _test_eof
	end
	if _goto_level <= _out
		break
	end
end
	end

# line 117 "lib/stomp_parser/stomp/ruby_parser.rb.rl"

        if mark
          state.chunk = chunk
        else
          state.chunk = nil
        end

        state.cs = cs
        state.mark = mark
        state.mark_key = mark_key
        state.mark_message = mark_message
        state.mark_message_size = mark_message_size
        state.mark_content_length = mark_content_length

        if cs == RubyParser.error
          Stomp.build_parse_error(chunk, p)
        else
          nil
        end
      end

      def initialize(max_message_size = Stomp.max_message_size)
        @state = State.new
        @max_message_size = Integer(max_message_size)
      end

      # Parse a chunk.
      #
      # @param [String] chunk
      # @yield [message]
      # @yieldparam [Stomp::Message] message
      def parse(chunk)
        @error ||= self.class._parse(chunk, @state, @max_message_size) do |message|
          yield message
        end

        raise @error if @error
      end
    end
  end
end
