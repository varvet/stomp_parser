#include "stomp_parser.h"
#include <ruby/encoding.h>

extern VALUE mStompParser;
extern VALUE eError;
ID g_command;
ID g_headers;
ID g_body;
ID g_force_encoding;
VALUE g_content_type;
VALUE g_content_length_h;

static VALUE frame_unescape_header(VALUE self, VALUE value) {
  int length = RSTRING_LEN(value);
  int i = 0, j = 0;

  if (length == 0) {
    return Qnil;
  }

  char *result = ALLOC_N(char, length + 1);
  char *source = RSTRING_PTR(value);

  for (i = 0, j = 0; i < length; ++i, ++j) {
    char chr = source[i];

    if (chr == '\\') {
      switch (source[i+1]) {
        case 'r':
          ++i;
          chr = '\r';
          break;
        case 'n':
          ++i;
          chr = '\n';
          break;
        case 'c':
          ++i;
          chr = ':';
          break;
        case '\\':
          ++i;
          chr = '\\';
          break;
      }
    }

    result[j] = chr;
  }

  return rb_enc_str_new(result, j, rb_utf8_encoding());
}

long frame_content_length(VALUE self) {
  VALUE headers = rb_ivar_get(self, g_headers);
  VALUE content_length = rb_hash_lookup2(headers, g_content_length_h, Qnil);
  if (content_length != Qnil) {
    char *start;
    long length;
    RSTRING_GETMEM(content_length, start, length);
    char *end;
    long result = ruby_strtoul(start, &end, 10);

    if (end == start) { // no number
      rb_raise(eError, "invalid content length \"%s\"", start);
      return -1;
    } else {
      return result;
    }
  } else {
    return -1;
  }
}

void frame_write_command(VALUE self, VALUE command) {
  rb_ivar_set(self, g_command, command);
}

void frame_write_header(VALUE self, VALUE key, VALUE value) {
  VALUE headers = rb_ivar_get(self, g_headers);

  key = frame_unescape_header(self, key);
  VALUE written = Qnil;

  if (rb_hash_lookup2(headers, key, Qundef) == Qundef) {
    written = frame_unescape_header(self, value);
    rb_hash_aset(headers, key, written);
  }
}

void frame_write_body(VALUE self, VALUE body) {
  VALUE headers = rb_ivar_get(self, g_headers);
  VALUE content_type = rb_hash_lookup(headers, g_content_type);
  rb_encoding *encoding = rb_ascii8bit_encoding();

  if (TYPE(content_type) == T_STRING) {
    const char *c_content_type;
    size_t length;
    RSTRING_GETMEM(content_type, c_content_type, length);

    const char *charset = strstr(c_content_type, ";charset=");
    if (charset != NULL) {
      charset += 9;
    }

    if (charset == NULL && strncmp(c_content_type, "text/", 5) == 0) {
      encoding = rb_utf8_encoding();
    } else if (charset != NULL) {
      encoding = rb_enc_find(charset);
    }
  }

  rb_enc_associate(body, encoding);
  rb_ivar_set(self, g_body, body);
}

void Init_c_frame(void) {
  VALUE cFrame = rb_const_get(mStompParser, rb_intern("CFrame"));

  g_command = rb_intern("@command");
  g_headers = rb_intern("@headers");
  g_body = rb_intern("@body");
  g_force_encoding = rb_intern("force_encoding");

  g_content_type = rb_str_new2("content-type");
  g_content_length_h = rb_str_new2("content-length");
  rb_global_variable(&g_content_length_h);
  rb_global_variable(&g_content_type);
}
