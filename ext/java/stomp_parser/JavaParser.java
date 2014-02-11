
// line 1 "ext/java/stomp_parser/JavaParser.java.rl"
package stomp_parser;

import org.jruby.Ruby;
import org.jruby.RubyModule;
import org.jruby.RubyClass;
import org.jruby.RubyObject;
import org.jruby.RubyFixnum;
import org.jruby.RubyString;
import org.jruby.RubyNumeric;
import org.jruby.RubyException;
import org.jruby.exceptions.RaiseException;

import org.jruby.runtime.ThreadContext;
import org.jruby.runtime.builtin.IRubyObject;
import org.jruby.runtime.Block;

import org.jruby.anno.JRubyClass;
import org.jruby.anno.JRubyMethod;


// line 88 "ext/java/stomp_parser/JavaParser.java.rl"


@JRubyClass(name="JavaParser", parent="Object")
public class JavaParser extends RubyObject {
  
// line 30 "ext/java/stomp_parser/JavaParser.java"
private static byte[] init__actions_0()
{
	return new byte [] {
	    0,    1,    0,    1,    7,    2,    0,    7,    2,    2,    7,    2,
	    3,    7,    2,    4,    7,    2,    5,    7,    3,    0,    4,    7,
	    3,    1,    0,    7,    3,    6,    8,    7
	};
}

private static final byte _actions[] = init__actions_0();


private static byte[] init__cond_offsets_0()
{
	return new byte [] {
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    3,    6,    6,    6,    6,    6,    6,    6,    6,
	    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
	    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
	    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,
	    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6,    6
	};
}

private static final byte _cond_offsets[] = init__cond_offsets_0();


private static byte[] init__cond_lengths_0()
{
	return new byte [] {
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    3,    3,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	};
}

private static final byte _cond_lengths[] = init__cond_lengths_0();


private static short[] init__cond_keys_0()
{
	return new short [] {
	 -128,   -1,    0,    0,    1,  127, -128,   -1,    0,    0,    1,  127,
	    0
	};
}

private static final short _cond_keys[] = init__cond_keys_0();


private static byte[] init__cond_spaces_0()
{
	return new byte [] {
	    1,    0,    1,    1,    0,    1,    0
	};
}

private static final byte _cond_spaces[] = init__cond_spaces_0();


private static byte[] init__key_offsets_0()
{
	return new byte [] {
	    0,    0,    1,    3,    4,    5,    6,    8,   12,   16,   20,   24,
	   25,   29,   33,   39,   45,   46,   47,   48,   49,   50,   51,   52,
	   54,   55,   56,   57,   58,   59,   60,   63,   64,   65,   66,   67,
	   68,   69,   70,   71,   72,   73,   74,   75,   76,   77,   78,   79,
	   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,   92,   93,
	   94,   95,   96,   97,   98,   99,  100,  101,  102,  103,  104,  105
	};
}

private static final byte _key_offsets[] = init__key_offsets_0();


private static short[] init__trans_keys_0()
{
	return new short [] {
	   10,   66,   67,   79,   82,   84,   10,   13,   10,   13,   58,   92,
	   10,   13,   58,   92,   10,   13,   58,   92,   10,   13,   58,   92,
	   10,   92,   99,  110,  114,   92,   99,  110,  114,  256,  512,  896,
	 1023, 1025, 1151,  256,  512,  896, 1023, 1025, 1151,   10,   75,   69,
	   71,   73,   78,   79,   77,   78,   77,   73,   78,   69,   67,   84,
	   10,   13,   69,   68,   73,   83,   67,   79,   78,   78,   69,   67,
	   82,   82,   79,   82,   69,   83,   83,   65,   71,   69,   65,   67,
	   69,   67,   69,   73,   80,   69,   84,   85,   78,   79,   77,   80,
	   66,   83,   67,   82,   73,   66,   78,   83,   85,   10,   13,   65,
	   66,   67,   68,   69,   77,   78,   82,   83,   85,    0
	};
}

private static final short _trans_keys[] = init__trans_keys_0();


private static byte[] init__single_lengths_0()
{
	return new byte [] {
	    0,    1,    2,    1,    1,    1,    2,    4,    4,    4,    4,    1,
	    4,    4,    2,    2,    1,    1,    1,    1,    1,    1,    1,    2,
	    1,    1,    1,    1,    1,    1,    3,    1,    1,    1,    1,    1,
	    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
	    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,    1,    1,
	    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,   12
	};
}

private static final byte _single_lengths[] = init__single_lengths_0();


private static byte[] init__range_lengths_0()
{
	return new byte [] {
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    2,    2,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	};
}

private static final byte _range_lengths[] = init__range_lengths_0();


private static short[] init__index_offsets_0()
{
	return new short [] {
	    0,    0,    2,    5,    7,    9,   11,   14,   19,   24,   29,   34,
	   36,   41,   46,   51,   56,   58,   60,   62,   64,   66,   68,   70,
	   73,   75,   77,   79,   81,   83,   85,   89,   91,   93,   95,   97,
	   99,  101,  103,  105,  107,  109,  111,  113,  115,  117,  119,  121,
	  123,  125,  127,  129,  131,  133,  135,  137,  139,  141,  145,  147,
	  149,  151,  153,  155,  157,  159,  161,  163,  165,  167,  169,  171
	};
}

private static final short _index_offsets[] = init__index_offsets_0();


private static byte[] init__indicies_0()
{
	return new byte [] {
	    0,    1,    2,    3,    1,    4,    1,    5,    1,    6,    1,    7,
	    8,    1,   10,   11,    1,   12,    9,    1,    1,   14,   15,   13,
	   17,   18,    1,   19,   16,   21,   22,    1,   23,   20,   24,    1,
	   20,   20,   20,   20,    1,   13,   13,   13,   13,    1,   25,   26,
	   26,   26,    1,   25,   26,   26,   26,    1,   27,    1,    6,    1,
	   28,    1,   29,    1,   30,    1,    6,    1,   31,    1,   32,   33,
	    1,   34,    1,    5,    1,   35,    1,   36,    1,   37,    1,   38,
	    1,    7,    8,   39,    1,    6,    1,   40,    1,   41,    1,   42,
	    1,   43,    1,   44,    1,   45,    1,   46,    1,    5,    1,   47,
	    1,   48,    1,   49,    1,    6,    1,   50,    1,   51,    1,   52,
	    1,   53,    1,   54,    1,    6,    1,   55,    1,    3,    1,   56,
	    1,   57,    1,   58,    1,   59,    1,    5,    1,   60,   61,   62,
	    1,   39,    1,   63,    1,   64,    1,    6,    1,   65,    1,   66,
	    1,   67,    1,   68,    1,   69,    1,   54,    1,   70,    1,   71,
	    1,   62,    1,    0,   72,   73,   74,   75,   76,   77,   78,   79,
	   80,   81,   82,    1,    0
	};
}

private static final byte _indicies[] = init__indicies_0();


private static byte[] init__trans_targs_0()
{
	return new byte [] {
	   71,    0,    3,   17,    4,    5,    6,    7,   11,    8,   14,   16,
	   13,    8,    9,   13,   10,    7,   11,   12,   10,    7,   11,   12,
	    7,   71,   15,   14,   19,   20,   21,   23,   24,   26,   25,   27,
	   28,   29,   30,   31,   33,   34,   35,   36,   37,   38,   39,   41,
	   42,   43,   45,   46,   47,   48,   49,   51,   53,   54,   55,   56,
	   58,   59,   62,   60,   61,   63,   64,   65,   66,   67,   69,   70,
	    1,    2,   18,   22,   32,   40,   44,   50,   52,   57,   68
	};
}

private static final byte _trans_targs[] = init__trans_targs_0();


private static byte[] init__trans_actions_0()
{
	return new byte [] {
	    0,    0,    3,    3,    3,    3,    3,    8,    8,    5,   17,   17,
	    5,    3,   11,    3,    5,   20,   20,    5,    3,   14,   14,    3,
	    3,   28,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
	    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
	    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
	    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
	    0,   24,   24,   24,   24,   24,   24,   24,   24,   24,   24
	};
}

private static final byte _trans_actions[] = init__trans_actions_0();


private static byte[] init__from_state_actions_0()
{
	return new byte [] {
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    1,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
	    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,    0
	};
}

private static final byte _from_state_actions[] = init__from_state_actions_0();


static final int start = 71;
static final int first_final = 71;
static final int error = 0;

static final int en_stream = 71;


// line 93 "ext/java/stomp_parser/JavaParser.java.rl"

  private class State {
    public int cs = JavaParser.start;
    public byte[] chunk;
    public int mark = -1;
    public RubyString mark_key;
    public IRubyObject mark_message;
    public int mark_message_size = -1;
    public int mark_content_length = -1;
  }

  private RubyException parseError;
  private long maxMessageSize;
  private State state;

  public JavaParser(Ruby runtime, RubyClass klass) {
    super(runtime, klass);
    state = new State();
    parseError = null;
  }

  @JRubyMethod
  public IRubyObject initialize(ThreadContext context) {
    RubyModule mStompParser = context.runtime.getClassFromPath("StompParser");
    return initialize(context, mStompParser.callMethod("max_message_size"));
  }

  @JRubyMethod(argTypes = {RubyFixnum.class})
  public IRubyObject initialize(ThreadContext context, IRubyObject maxMessageSize) {
    this.maxMessageSize = ((RubyFixnum) maxMessageSize).getLongValue();
    return context.nil;
  }

  @JRubyMethod(argTypes = {RubyString.class})
  public IRubyObject parse(ThreadContext context, IRubyObject chunk, Block block) {
    if (parseError == null) {
      int p;
      byte data[] = null;
      byte bytes[] = ((RubyString) chunk).getBytes();

      if (state.chunk != null) {
        p = state.chunk.length;
        data = new byte[state.chunk.length + bytes.length];
        System.arraycopy(state.chunk, 0, data, 0, state.chunk.length);
        System.arraycopy(bytes, 0, data, state.chunk.length, bytes.length);
      } else {
        p = 0;
        data = bytes;
      }

      int pe = data.length;

      int cs = state.cs;
      int mark = state.mark;
      RubyString mark_key = state.mark_key;
      IRubyObject mark_message = state.mark_message;
      int mark_message_size = state.mark_message_size;
      int mark_content_length = state.mark_content_length;

      
// line 313 "ext/java/stomp_parser/JavaParser.java"
	{
	int _klen;
	int _trans = 0;
	int _widec;
	int _acts;
	int _nacts;
	int _keys;
	int _goto_targ = 0;

	_goto: while (true) {
	switch ( _goto_targ ) {
	case 0:
	if ( p == pe ) {
		_goto_targ = 4;
		continue _goto;
	}
	if ( cs == 0 ) {
		_goto_targ = 5;
		continue _goto;
	}
case 1:
	_acts = _from_state_actions[cs];
	_nacts = (int) _actions[_acts++];
	while ( _nacts-- > 0 ) {
		switch ( _actions[_acts++] ) {
	case 0:
// line 24 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    mark = p;
  }
	break;
// line 345 "ext/java/stomp_parser/JavaParser.java"
		}
	}

	_widec = data[p];
	_keys = _cond_offsets[cs]*2
;	_klen = _cond_lengths[cs];
	if ( _klen > 0 ) {
		int _lower = _keys
;		int _mid;
		int _upper = _keys + (_klen<<1) - 2;
		while (true) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( _widec < _cond_keys[_mid] )
				_upper = _mid - 2;
			else if ( _widec > _cond_keys[_mid+1] )
				_lower = _mid + 2;
			else {
				switch ( _cond_spaces[_cond_offsets[cs] + ((_mid - _keys)>>1)] ) {
	case 0: {
		_widec = 128 + (data[p] - -128);
		if ( 
// line 65 "ext/java/stomp_parser/JavaParser.java.rl"

    ((mark_content_length != -1) && ((p - mark) < mark_content_length))
   ) _widec += 256;
		break;
	}
	case 1: {
		_widec = 640 + (data[p] - -128);
		if ( 
// line 69 "ext/java/stomp_parser/JavaParser.java.rl"

    ((mark_content_length == -1) || ((p - mark) < mark_content_length))
   ) _widec += 256;
		break;
	}
				}
				break;
			}
		}
	}

	_match: do {
	_keys = _key_offsets[cs];
	_trans = _index_offsets[cs];
	_klen = _single_lengths[cs];
	if ( _klen > 0 ) {
		int _lower = _keys;
		int _mid;
		int _upper = _keys + _klen - 1;
		while (true) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( _widec < _trans_keys[_mid] )
				_upper = _mid - 1;
			else if ( _widec > _trans_keys[_mid] )
				_lower = _mid + 1;
			else {
				_trans += (_mid - _keys);
				break _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _range_lengths[cs];
	if ( _klen > 0 ) {
		int _lower = _keys;
		int _mid;
		int _upper = _keys + (_klen<<1) - 2;
		while (true) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( _widec < _trans_keys[_mid] )
				_upper = _mid - 2;
			else if ( _widec > _trans_keys[_mid+1] )
				_lower = _mid + 2;
			else {
				_trans += ((_mid - _keys)>>1);
				break _match;
			}
		}
		_trans += _klen;
	}
	} while (false);

	_trans = _indicies[_trans];
	cs = _trans_targs[_trans];

	if ( _trans_actions[_trans] != 0 ) {
		_acts = _trans_actions[_trans];
		_nacts = (int) _actions[_acts++];
		while ( _nacts-- > 0 )
	{
			switch ( _actions[_acts++] )
			{
	case 0:
// line 24 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    mark = p;
  }
	break;
	case 1:
// line 28 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    mark_message = context.runtime.getClassFromPath("StompParser::Message").callMethod("new", context.nil, context.nil);
    mark_message_size = 0;
  }
	break;
	case 2:
// line 33 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    mark_message.callMethod(context, "write_command", RubyString.newString(context.runtime, data, mark, p - mark));
    mark = -1;
  }
	break;
	case 3:
// line 38 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    mark_key = RubyString.newString(context.runtime, data, mark, p - mark);
    mark = -1;
  }
	break;
	case 4:
// line 43 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    IRubyObject args[] = { mark_key, RubyString.newString(context.runtime, data, mark, p - mark) };
    mark_message.callMethod(context, "write_header", args);
    mark_key = null;
    mark = -1;
  }
	break;
	case 5:
// line 50 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    IRubyObject content_length = mark_message.callMethod(context, "content_length");

    if ( ! content_length.isNil()) {
      mark_content_length = RubyNumeric.num2int(content_length);
    } else {
      mark_content_length = -1;
    }
  }
	break;
	case 6:
// line 60 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    mark_message.callMethod(context, "write_body", RubyString.newString(context.runtime, data, mark, p - mark));
    mark = -1;
  }
	break;
	case 7:
// line 73 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > maxMessageSize) {
      RubyModule messageSizeExceeded = context.runtime.getClassFromPath("StompParser::MessageSizeExceeded");
      RubyException error = (RubyException) messageSizeExceeded.callMethod("new");
      throw new RaiseException(error);
    }
  }
	break;
	case 8:
// line 82 "ext/java/stomp_parser/JavaParser.java.rl"
	{
    block.yield(context, mark_message);
    mark_message = null;
  }
	break;
// line 523 "ext/java/stomp_parser/JavaParser.java"
			}
		}
	}

case 2:
	if ( cs == 0 ) {
		_goto_targ = 5;
		continue _goto;
	}
	if ( ++p != pe ) {
		_goto_targ = 1;
		continue _goto;
	}
case 4:
case 5:
	}
	break; }
	}

// line 153 "ext/java/stomp_parser/JavaParser.java.rl"

      if (mark != -1) {
        state.chunk = data;
      } else {
        state.chunk = null;
      }

      state.cs = cs;
      state.mark = mark;
      state.mark_key = mark_key;
      state.mark_message = mark_message;
      state.mark_message_size = mark_message_size;
      state.mark_content_length = mark_content_length;

      if (cs == error) {
        IRubyObject args[] = { RubyString.newString(context.runtime, data), RubyFixnum.newFixnum(context.runtime, (long) p) };
        parseError = (RubyException) context.runtime.getClassFromPath("StompParser").callMethod(context, "build_parse_error", args);
      }
    }

    if (parseError != null) {
      throw new RaiseException(parseError);
    }

    return context.nil;
  }
}
