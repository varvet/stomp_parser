#include <assert.h>
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

static VALUE frame_unescape_header(VALUE value) {
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

  VALUE final = rb_enc_str_new(result, j, rb_utf8_encoding());
  xfree(result);
  return final;
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

  key = frame_unescape_header(key);
  VALUE written = Qnil;

  if (rb_hash_lookup2(headers, key, Qundef) == Qundef) {
    written = frame_unescape_header(value);
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

static VALUE frame_escape_header(VALUE value) {
  int length = RSTRING_LEN(value);
  int i = 0, j = 0;

  if (length == 0) {
    return rb_str_new2("");
  }

  // If every character needs escaping, we need 2xLENGTH
  char *result = ALLOC_N(char, (length * 2) + 1);
  char *source = RSTRING_PTR(value);

  for (i = 0, j = 0; i < length; ++i, ++j) {
    char chr = source[i];

    switch (chr) {
      case '\n':
        result[j] = '\\';
        result[++j] = 'n';
        break;
      case '\r':
        result[j] = '\\';
        result[++j] = 'r';
        break;
      case ':':
        result[j] = '\\';
        result[++j] = 'c';
        break;
      case '\\':
        result[j] = '\\';
        result[++j] = '\\';
        break;
      default:
        result[j] = chr;
        break;
    }
  }

  VALUE final = rb_enc_str_new(result, j, rb_utf8_encoding());
  xfree(result);
  return final;
}

int build_headers_string(VALUE key, VALUE val, VALUE headers_string) {
  if (memcmp(RSTRING_PTR(key), "content-length", sizeof("content-length")) == 0) {
    return ST_CONTINUE;
  }

  key = frame_escape_header(key);
  val = frame_escape_header(val);
  rb_str_buf_cat(headers_string, RSTRING_PTR(key), RSTRING_LEN(key));
  rb_str_buf_cat(headers_string, ":", 1);
  rb_str_buf_cat(headers_string, RSTRING_PTR(val), RSTRING_LEN(val));
  rb_str_buf_cat(headers_string, "\n", 1);

  return ST_CONTINUE;
}

VALUE frame_serialize(VALUE self) {
  VALUE command = rb_ivar_get(self, g_command);

  VALUE headers = rb_ivar_get(self, g_headers);
  VALUE headers_string = Qnil;
  long headers_length = 0;

  if ( ! RHASH_EMPTY_P(headers)) {
    headers_string = rb_str_buf_new(0);
    rb_hash_foreach(headers, build_headers_string, headers_string);
    headers_length = RSTRING_LEN(headers_string);
  }

  VALUE body = rb_ivar_get(self, g_body);
  long body_length = RSTRING_LEN(body);

  char content_length_str[32];
  long content_length_len = snprintf(content_length_str, sizeof(content_length_str), "content-length:%ld\n", body_length);

  VALUE serialized = rb_str_buf_new(0);
  rb_str_buf_cat(serialized, RSTRING_PTR(command), RSTRING_LEN(command));
  rb_str_buf_cat(serialized, "\n", 1);
  if (headers_length > 0) {
    rb_str_buf_cat(serialized, RSTRING_PTR(headers_string), headers_length);
  }
  rb_str_buf_cat(serialized, content_length_str, content_length_len);
  rb_str_buf_cat(serialized, "\n", 1);
  if (body_length > 0) {
    rb_str_buf_cat(serialized, RSTRING_PTR(body), body_length);
  }
  rb_str_buf_cat(serialized, "\0", 1);

  return serialized;
}

void Init_c_frame(void) {
  VALUE cFrame = rb_const_get(mStompParser, rb_intern("CFrame"));
  rb_define_method(cFrame, "to_str", frame_serialize, 0);

  g_command = rb_intern("@command");
  g_headers = rb_intern("@headers");
  g_body = rb_intern("@body");
  g_force_encoding = rb_intern("force_encoding");

  g_content_type = rb_str_new2("content-type");
  g_content_length_h = rb_str_new2("content-length");
  rb_global_variable(&g_content_length_h);
  rb_global_variable(&g_content_type);
}
