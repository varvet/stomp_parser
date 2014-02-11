
#line 1 "ext/stomp_parser/c_parser.c.rl"
#include <ruby.h>

#if DEBUG_H
#  define DEBUG(fmt, ...) do { fprintf(stderr, fmt "\n", ##__VA_ARGS__); } while(0)
#else
#  define DEBUG(...)
#endif

#define UNUSED(x) (void)(x)
#define MARK_LEN (p - mark)
#define MARK_STR_NEW() rb_str_new(mark, MARK_LEN)

#define true 1
#define false 0

typedef struct {
  VALUE error;
  long max_message_size;

  VALUE chunk;
  const char *p;
  int cs;
  const char *mark;
  VALUE mark_key;
  VALUE mark_message;
  long mark_message_size;
  long mark_content_length;
} parser_state_t;

VALUE mStomp = Qnil;
VALUE cMessage = Qnil;
VALUE eMessageSizeExceeded = Qnil;
ID g_new;
ID g_write_command;
ID g_write_header;
ID g_write_body;
ID g_content_length;
ID g_build_parse_error;
ID g_max_message_size;


#line 45 "ext/stomp_parser/c_parser.c"
static const int start = 71;
static const int first_final = 71;
static const int error = 0;

static const int en_stream = 71;


#line 106 "ext/stomp_parser/c_parser.c.rl"


static void parser_free(parser_state_t *state) {
  // TODO: free memory inside struct!
  xfree(state);
}

static void parser_mark(parser_state_t *state) {
  rb_gc_mark(state->error);
  rb_gc_mark(state->mark_key);
  rb_gc_mark(state->mark_message);
  rb_gc_mark(state->chunk);
}

static VALUE parser_alloc(VALUE klass) {
  parser_state_t *state = ALLOC(parser_state_t);
  return Data_Wrap_Struct(klass, parser_mark, parser_free, state);
}

static VALUE parser_initialize(int argc, VALUE *argv, VALUE self) {
  parser_state_t *state;
  Data_Get_Struct(self, parser_state_t, state);

  VALUE max_message_size;
  rb_scan_args(argc, argv, "01", &max_message_size);

  if (max_message_size == Qnil) {
    max_message_size = rb_funcall(mStomp, g_max_message_size, 0);
  }

  state->error = Qnil;
  state->max_message_size = FIX2LONG(max_message_size);
  state->chunk = Qnil;
  state->cs = start;
  state->mark = NULL;
  state->mark_key = Qnil;
  state->mark_message = Qnil;
  state->mark_message_size = 0;
  state->mark_content_length = 0;

  return self;
}

static VALUE parser_parse(VALUE self, VALUE new_chunk) {
  parser_state_t *state;
  Data_Get_Struct(self, parser_state_t, state);

  if (NIL_P(state->error)) {
    VALUE chunk = Qnil;
    const char *p = NULL;
    const char *mark = NULL;

    if ( ! NIL_P(state->chunk)) {
      long offset = RSTRING_LEN(state->chunk);
      long mark_offset = state->mark - RSTRING_PTR(state->chunk);

      chunk = rb_str_append(state->chunk, new_chunk);
      p = RSTRING_PTR(chunk) + offset;
      mark = RSTRING_PTR(chunk) + mark_offset;
    } else {
      chunk = new_chunk;
      p = RSTRING_PTR(chunk);
    }

    const char *pe = RSTRING_END(chunk);
    long max_message_size = state->max_message_size;

    int cs = state->cs;
    VALUE mark_key = state->mark_key;
    VALUE mark_message = state->mark_message;
    long mark_message_size = state->mark_message_size;
    long mark_content_length = state->mark_content_length;

    
#line 128 "ext/stomp_parser/c_parser.c"
	{
	short _widec;
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr25:
#line 78 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_funcall(mark_message, g_write_body, 1, MARK_STR_NEW());
    mark = NULL;
  }
#line 98 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_yield(mark_message);
    mark_message = Qnil;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st71;
st71:
	if ( ++p == pe )
		goto _test_eof71;
case 71:
#line 158 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 10: goto st71;
		case 13: goto st1;
		case 65: goto tr73;
		case 66: goto tr74;
		case 67: goto tr75;
		case 68: goto tr76;
		case 69: goto tr77;
		case 77: goto tr78;
		case 78: goto tr79;
		case 82: goto tr80;
		case 83: goto tr81;
		case 85: goto tr82;
	}
	goto st0;
st0:
cs = 0;
	goto _out;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	if ( (*p) == 10 )
		goto st71;
	goto st0;
tr73:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
#line 206 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 66: goto tr2;
		case 67: goto tr3;
	}
	goto st0;
tr2:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st3;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
#line 225 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 79 )
		goto tr4;
	goto st0;
tr4:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st4;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
#line 242 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 82 )
		goto tr5;
	goto st0;
tr5:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st5;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
#line 259 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 84 )
		goto tr6;
	goto st0;
tr6:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st6;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
#line 276 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 10: goto tr7;
		case 13: goto tr8;
	}
	goto st0;
tr24:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st7;
tr7:
#line 53 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_funcall(mark_message, g_write_command, 1, MARK_STR_NEW());
    mark = NULL;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st7;
tr17:
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 63 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_funcall(mark_message, g_write_header, 2, mark_key, MARK_STR_NEW());
    mark_key = Qnil;
    mark = NULL;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st7;
tr21:
#line 63 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_funcall(mark_message, g_write_header, 2, mark_key, MARK_STR_NEW());
    mark_key = Qnil;
    mark = NULL;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st7;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
#line 343 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 10: goto tr10;
		case 13: goto tr11;
		case 58: goto st0;
		case 92: goto tr12;
	}
	goto tr9;
tr13:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st8;
tr9:
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st8;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
#line 377 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 10: goto st0;
		case 13: goto st0;
		case 58: goto tr14;
		case 92: goto tr15;
	}
	goto tr13;
tr14:
#line 58 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_key = MARK_STR_NEW();
    mark = NULL;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st9;
st9:
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 403 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 10: goto tr17;
		case 13: goto tr18;
		case 58: goto st0;
		case 92: goto tr19;
	}
	goto tr16;
tr20:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st10;
tr16:
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st10;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
#line 437 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 10: goto tr21;
		case 13: goto tr22;
		case 58: goto st0;
		case 92: goto tr23;
	}
	goto tr20;
tr8:
#line 53 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_funcall(mark_message, g_write_command, 1, MARK_STR_NEW());
    mark = NULL;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st11;
tr18:
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 63 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_funcall(mark_message, g_write_header, 2, mark_key, MARK_STR_NEW());
    mark_key = Qnil;
    mark = NULL;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st11;
tr22:
#line 63 "ext/stomp_parser/c_parser.c.rl"
	{
    rb_funcall(mark_message, g_write_header, 2, mark_key, MARK_STR_NEW());
    mark_key = Qnil;
    mark = NULL;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st11;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
#line 497 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 10 )
		goto tr24;
	goto st0;
tr23:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st12;
tr19:
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st12;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
#line 527 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 92: goto tr20;
		case 99: goto tr20;
		case 110: goto tr20;
		case 114: goto tr20;
	}
	goto st0;
tr15:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st13;
tr12:
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st13;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
#line 561 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 92: goto tr13;
		case 99: goto tr13;
		case 110: goto tr13;
		case 114: goto tr13;
	}
	goto st0;
tr27:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st14;
tr10:
#line 69 "ext/stomp_parser/c_parser.c.rl"
	{
    VALUE length = rb_funcall(mark_message, g_content_length, 0);
    if ( ! NIL_P(length)) {
      mark_content_length = NUM2LONG(length);
    } else {
      mark_content_length = -1;
    }
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st14;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 604 "ext/stomp_parser/c_parser.c"
	_widec = (*p);
	if ( (*p) < 0 ) {
		if ( (*p) <= -1 ) {
			_widec = (short)(640 + ((*p) - -128));
			if ( 
#line 87 "ext/stomp_parser/c_parser.c.rl"

    ((mark_content_length == -1) || (MARK_LEN < mark_content_length))
   ) _widec += 256;
		}
	} else if ( (*p) > 0 ) {
		if ( 1 <= (*p) )
 {			_widec = (short)(640 + ((*p) - -128));
			if ( 
#line 87 "ext/stomp_parser/c_parser.c.rl"

    ((mark_content_length == -1) || (MARK_LEN < mark_content_length))
   ) _widec += 256;
		}
	} else {
		_widec = (short)(128 + ((*p) - -128));
		if ( 
#line 83 "ext/stomp_parser/c_parser.c.rl"

    ((mark_content_length != -1) && (MARK_LEN < mark_content_length))
   ) _widec += 256;
	}
	switch( _widec ) {
		case 256: goto tr25;
		case 512: goto tr26;
	}
	if ( _widec > 1023 ) {
		if ( 1025 <= _widec && _widec <= 1151 )
			goto tr26;
	} else if ( _widec >= 896 )
		goto tr26;
	goto st0;
tr26:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st15;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
#line 655 "ext/stomp_parser/c_parser.c"
	_widec = (*p);
	if ( (*p) < 0 ) {
		if ( (*p) <= -1 ) {
			_widec = (short)(640 + ((*p) - -128));
			if ( 
#line 87 "ext/stomp_parser/c_parser.c.rl"

    ((mark_content_length == -1) || (MARK_LEN < mark_content_length))
   ) _widec += 256;
		}
	} else if ( (*p) > 0 ) {
		if ( 1 <= (*p) )
 {			_widec = (short)(640 + ((*p) - -128));
			if ( 
#line 87 "ext/stomp_parser/c_parser.c.rl"

    ((mark_content_length == -1) || (MARK_LEN < mark_content_length))
   ) _widec += 256;
		}
	} else {
		_widec = (short)(128 + ((*p) - -128));
		if ( 
#line 83 "ext/stomp_parser/c_parser.c.rl"

    ((mark_content_length != -1) && (MARK_LEN < mark_content_length))
   ) _widec += 256;
	}
	switch( _widec ) {
		case 256: goto tr25;
		case 512: goto tr26;
	}
	if ( _widec > 1023 ) {
		if ( 1025 <= _widec && _widec <= 1151 )
			goto tr26;
	} else if ( _widec >= 896 )
		goto tr26;
	goto st0;
tr11:
#line 69 "ext/stomp_parser/c_parser.c.rl"
	{
    VALUE length = rb_funcall(mark_message, g_content_length, 0);
    if ( ! NIL_P(length)) {
      mark_content_length = NUM2LONG(length);
    } else {
      mark_content_length = -1;
    }
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 715 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 10 )
		goto tr27;
	goto st0;
tr3:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st17;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
#line 732 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 75 )
		goto tr6;
	goto st0;
tr74:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st18;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
#line 758 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 69 )
		goto tr28;
	goto st0;
tr28:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st19;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
#line 775 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 71 )
		goto tr29;
	goto st0;
tr29:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st20;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
#line 792 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 73 )
		goto tr30;
	goto st0;
tr30:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st21;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
#line 809 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 78 )
		goto tr6;
	goto st0;
tr75:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st22;
st22:
	if ( ++p == pe )
		goto _test_eof22;
case 22:
#line 835 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 79 )
		goto tr31;
	goto st0;
tr31:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st23;
st23:
	if ( ++p == pe )
		goto _test_eof23;
case 23:
#line 852 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 77: goto tr32;
		case 78: goto tr33;
	}
	goto st0;
tr32:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st24;
st24:
	if ( ++p == pe )
		goto _test_eof24;
case 24:
#line 871 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 77 )
		goto tr34;
	goto st0;
tr34:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st25;
st25:
	if ( ++p == pe )
		goto _test_eof25;
case 25:
#line 888 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 73 )
		goto tr5;
	goto st0;
tr33:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st26;
st26:
	if ( ++p == pe )
		goto _test_eof26;
case 26:
#line 905 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 78 )
		goto tr35;
	goto st0;
tr35:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st27;
st27:
	if ( ++p == pe )
		goto _test_eof27;
case 27:
#line 922 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 69 )
		goto tr36;
	goto st0;
tr36:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st28;
st28:
	if ( ++p == pe )
		goto _test_eof28;
case 28:
#line 939 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 67 )
		goto tr37;
	goto st0;
tr37:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st29;
st29:
	if ( ++p == pe )
		goto _test_eof29;
case 29:
#line 956 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 84 )
		goto tr38;
	goto st0;
tr38:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st30;
st30:
	if ( ++p == pe )
		goto _test_eof30;
case 30:
#line 973 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 10: goto tr7;
		case 13: goto tr8;
		case 69: goto tr39;
	}
	goto st0;
tr39:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st31;
st31:
	if ( ++p == pe )
		goto _test_eof31;
case 31:
#line 993 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 68 )
		goto tr6;
	goto st0;
tr76:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st32;
st32:
	if ( ++p == pe )
		goto _test_eof32;
case 32:
#line 1019 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 73 )
		goto tr40;
	goto st0;
tr40:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st33;
st33:
	if ( ++p == pe )
		goto _test_eof33;
case 33:
#line 1036 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 83 )
		goto tr41;
	goto st0;
tr41:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st34;
st34:
	if ( ++p == pe )
		goto _test_eof34;
case 34:
#line 1053 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 67 )
		goto tr42;
	goto st0;
tr42:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st35;
st35:
	if ( ++p == pe )
		goto _test_eof35;
case 35:
#line 1070 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 79 )
		goto tr43;
	goto st0;
tr43:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st36;
st36:
	if ( ++p == pe )
		goto _test_eof36;
case 36:
#line 1087 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 78 )
		goto tr44;
	goto st0;
tr44:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st37;
st37:
	if ( ++p == pe )
		goto _test_eof37;
case 37:
#line 1104 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 78 )
		goto tr45;
	goto st0;
tr45:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st38;
st38:
	if ( ++p == pe )
		goto _test_eof38;
case 38:
#line 1121 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 69 )
		goto tr46;
	goto st0;
tr46:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st39;
st39:
	if ( ++p == pe )
		goto _test_eof39;
case 39:
#line 1138 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 67 )
		goto tr5;
	goto st0;
tr77:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st40;
st40:
	if ( ++p == pe )
		goto _test_eof40;
case 40:
#line 1164 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 82 )
		goto tr47;
	goto st0;
tr47:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st41;
st41:
	if ( ++p == pe )
		goto _test_eof41;
case 41:
#line 1181 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 82 )
		goto tr48;
	goto st0;
tr48:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st42;
st42:
	if ( ++p == pe )
		goto _test_eof42;
case 42:
#line 1198 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 79 )
		goto tr49;
	goto st0;
tr49:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st43;
st43:
	if ( ++p == pe )
		goto _test_eof43;
case 43:
#line 1215 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 82 )
		goto tr6;
	goto st0;
tr78:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st44;
st44:
	if ( ++p == pe )
		goto _test_eof44;
case 44:
#line 1241 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 69 )
		goto tr50;
	goto st0;
tr50:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st45;
st45:
	if ( ++p == pe )
		goto _test_eof45;
case 45:
#line 1258 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 83 )
		goto tr51;
	goto st0;
tr51:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st46;
st46:
	if ( ++p == pe )
		goto _test_eof46;
case 46:
#line 1275 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 83 )
		goto tr52;
	goto st0;
tr52:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st47;
st47:
	if ( ++p == pe )
		goto _test_eof47;
case 47:
#line 1292 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 65 )
		goto tr53;
	goto st0;
tr53:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st48;
st48:
	if ( ++p == pe )
		goto _test_eof48;
case 48:
#line 1309 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 71 )
		goto tr54;
	goto st0;
tr54:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st49;
st49:
	if ( ++p == pe )
		goto _test_eof49;
case 49:
#line 1326 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 69 )
		goto tr6;
	goto st0;
tr79:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st50;
st50:
	if ( ++p == pe )
		goto _test_eof50;
case 50:
#line 1352 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 65 )
		goto tr55;
	goto st0;
tr55:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st51;
st51:
	if ( ++p == pe )
		goto _test_eof51;
case 51:
#line 1369 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 67 )
		goto tr3;
	goto st0;
tr80:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st52;
st52:
	if ( ++p == pe )
		goto _test_eof52;
case 52:
#line 1395 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 69 )
		goto tr56;
	goto st0;
tr56:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st53;
st53:
	if ( ++p == pe )
		goto _test_eof53;
case 53:
#line 1412 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 67 )
		goto tr57;
	goto st0;
tr57:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st54;
st54:
	if ( ++p == pe )
		goto _test_eof54;
case 54:
#line 1429 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 69 )
		goto tr58;
	goto st0;
tr58:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st55;
st55:
	if ( ++p == pe )
		goto _test_eof55;
case 55:
#line 1446 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 73 )
		goto tr59;
	goto st0;
tr59:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st56;
st56:
	if ( ++p == pe )
		goto _test_eof56;
case 56:
#line 1463 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 80 )
		goto tr5;
	goto st0;
tr81:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st57;
st57:
	if ( ++p == pe )
		goto _test_eof57;
case 57:
#line 1489 "ext/stomp_parser/c_parser.c"
	switch( (*p) ) {
		case 69: goto tr60;
		case 84: goto tr61;
		case 85: goto tr62;
	}
	goto st0;
tr60:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st58;
st58:
	if ( ++p == pe )
		goto _test_eof58;
case 58:
#line 1509 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 78 )
		goto tr39;
	goto st0;
tr61:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st59;
st59:
	if ( ++p == pe )
		goto _test_eof59;
case 59:
#line 1526 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 79 )
		goto tr63;
	goto st0;
tr63:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st60;
st60:
	if ( ++p == pe )
		goto _test_eof60;
case 60:
#line 1543 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 77 )
		goto tr64;
	goto st0;
tr64:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st61;
st61:
	if ( ++p == pe )
		goto _test_eof61;
case 61:
#line 1560 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 80 )
		goto tr6;
	goto st0;
tr62:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st62;
st62:
	if ( ++p == pe )
		goto _test_eof62;
case 62:
#line 1577 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 66 )
		goto tr65;
	goto st0;
tr65:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st63;
st63:
	if ( ++p == pe )
		goto _test_eof63;
case 63:
#line 1594 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 83 )
		goto tr66;
	goto st0;
tr66:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st64;
st64:
	if ( ++p == pe )
		goto _test_eof64;
case 64:
#line 1611 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 67 )
		goto tr67;
	goto st0;
tr67:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st65;
st65:
	if ( ++p == pe )
		goto _test_eof65;
case 65:
#line 1628 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 82 )
		goto tr68;
	goto st0;
tr68:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st66;
st66:
	if ( ++p == pe )
		goto _test_eof66;
case 66:
#line 1645 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 73 )
		goto tr69;
	goto st0;
tr69:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st67;
st67:
	if ( ++p == pe )
		goto _test_eof67;
case 67:
#line 1662 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 66 )
		goto tr54;
	goto st0;
tr82:
#line 48 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message = rb_funcall(cMessage, g_new, 2, Qnil, Qnil);
    mark_message_size = 0;
  }
#line 44 "ext/stomp_parser/c_parser.c.rl"
	{
    mark = p;
  }
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st68;
st68:
	if ( ++p == pe )
		goto _test_eof68;
case 68:
#line 1688 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 78 )
		goto tr70;
	goto st0;
tr70:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st69;
st69:
	if ( ++p == pe )
		goto _test_eof69;
case 69:
#line 1705 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 83 )
		goto tr71;
	goto st0;
tr71:
#line 91 "ext/stomp_parser/c_parser.c.rl"
	{
    mark_message_size += 1;
    if (mark_message_size > max_message_size) {
      rb_raise(eMessageSizeExceeded, "");
    }
  }
	goto st70;
st70:
	if ( ++p == pe )
		goto _test_eof70;
case 70:
#line 1722 "ext/stomp_parser/c_parser.c"
	if ( (*p) == 85 )
		goto tr62;
	goto st0;
	}
	_test_eof71: cs = 71; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 
	_test_eof22: cs = 22; goto _test_eof; 
	_test_eof23: cs = 23; goto _test_eof; 
	_test_eof24: cs = 24; goto _test_eof; 
	_test_eof25: cs = 25; goto _test_eof; 
	_test_eof26: cs = 26; goto _test_eof; 
	_test_eof27: cs = 27; goto _test_eof; 
	_test_eof28: cs = 28; goto _test_eof; 
	_test_eof29: cs = 29; goto _test_eof; 
	_test_eof30: cs = 30; goto _test_eof; 
	_test_eof31: cs = 31; goto _test_eof; 
	_test_eof32: cs = 32; goto _test_eof; 
	_test_eof33: cs = 33; goto _test_eof; 
	_test_eof34: cs = 34; goto _test_eof; 
	_test_eof35: cs = 35; goto _test_eof; 
	_test_eof36: cs = 36; goto _test_eof; 
	_test_eof37: cs = 37; goto _test_eof; 
	_test_eof38: cs = 38; goto _test_eof; 
	_test_eof39: cs = 39; goto _test_eof; 
	_test_eof40: cs = 40; goto _test_eof; 
	_test_eof41: cs = 41; goto _test_eof; 
	_test_eof42: cs = 42; goto _test_eof; 
	_test_eof43: cs = 43; goto _test_eof; 
	_test_eof44: cs = 44; goto _test_eof; 
	_test_eof45: cs = 45; goto _test_eof; 
	_test_eof46: cs = 46; goto _test_eof; 
	_test_eof47: cs = 47; goto _test_eof; 
	_test_eof48: cs = 48; goto _test_eof; 
	_test_eof49: cs = 49; goto _test_eof; 
	_test_eof50: cs = 50; goto _test_eof; 
	_test_eof51: cs = 51; goto _test_eof; 
	_test_eof52: cs = 52; goto _test_eof; 
	_test_eof53: cs = 53; goto _test_eof; 
	_test_eof54: cs = 54; goto _test_eof; 
	_test_eof55: cs = 55; goto _test_eof; 
	_test_eof56: cs = 56; goto _test_eof; 
	_test_eof57: cs = 57; goto _test_eof; 
	_test_eof58: cs = 58; goto _test_eof; 
	_test_eof59: cs = 59; goto _test_eof; 
	_test_eof60: cs = 60; goto _test_eof; 
	_test_eof61: cs = 61; goto _test_eof; 
	_test_eof62: cs = 62; goto _test_eof; 
	_test_eof63: cs = 63; goto _test_eof; 
	_test_eof64: cs = 64; goto _test_eof; 
	_test_eof65: cs = 65; goto _test_eof; 
	_test_eof66: cs = 66; goto _test_eof; 
	_test_eof67: cs = 67; goto _test_eof; 
	_test_eof68: cs = 68; goto _test_eof; 
	_test_eof69: cs = 69; goto _test_eof; 
	_test_eof70: cs = 70; goto _test_eof; 

	_test_eof: {}
	_out: {}
	}

#line 180 "ext/stomp_parser/c_parser.c.rl"

    if (mark != NULL) {
      state->chunk = chunk;
    } else {
      state->chunk = Qnil;
    }

    state->cs = cs;
    state->mark = mark;
    state->mark_key = mark_key;
    state->mark_message = mark_message;
    state->mark_message_size = mark_message_size;
    state->mark_content_length = mark_content_length;

    if (cs == error) {
      long index = p - RSTRING_PTR(chunk);
      state->error = rb_funcall(mStomp, g_build_parse_error, 2, chunk, LONG2NUM(index));
    }
  }

  if ( ! NIL_P(state->error)) {
    rb_exc_raise(state->error);
  }

  return Qnil;
}

void Init_c_parser(void) {
  VALUE mStompParser = rb_const_get(rb_cObject, rb_intern("StompParser"));

  mStomp = rb_const_get(mStompParser, rb_intern("Stomp"));
  cMessage = rb_const_get(mStomp, rb_intern("Message"));
  eMessageSizeExceeded = rb_const_get(mStomp, rb_intern("MessageSizeExceeded"));

  g_new = rb_intern("new");
  g_write_command = rb_intern("write_command");
  g_write_header = rb_intern("write_header");
  g_write_body = rb_intern("write_body");
  g_content_length = rb_intern("content_length");
  g_build_parse_error = rb_intern("build_parse_error");
  g_max_message_size = rb_intern("max_message_size");

  VALUE cParser = rb_define_class_under(mStomp, "CParser", rb_cObject);
  rb_define_alloc_func(cParser, parser_alloc);

  rb_define_method(cParser, "initialize", parser_initialize, -1);
  rb_define_method(cParser, "parse", parser_parse, 1);
}
