#ifndef _STOMP_PARSER_H_
#define _STOMP_PARSER_H_ true

#include <ruby.h>

#if DEBUG_H
#  define DEBUG(fmt, ...) do { fprintf(stderr, fmt "\n", ##__VA_ARGS__); } while(0)
#else
#  define DEBUG(...)
#endif

#define UNUSED(x) (void)(x)
#define true 1
#define false 0

void Init_c_frame(void);
void frame_write_command(VALUE self, VALUE command);
void frame_write_header(VALUE self, VALUE key, VALUE value);
void frame_write_body(VALUE self, VALUE body);
long frame_content_length(VALUE self);

#endif
