#include <stdio.h>
#include <assert.h>

#include "hps_util.h"
#include "hps_token.h"

static void print_buffer(const char* buffer, hps_uint32_t start, hps_uint32_t end) {
	if (end == start) {
		return;
	}

	hps_uint32_t i = start;
	for (; i < end; ++i) {
		printf("%c", buffer[i]);
	}
	printf("\n");
}

static void begin_a_new_tag(const char* buffer, hps_uint32_t s, hps_uint32_t i) {
	assert(s <= i);
	print_buffer(buffer, s, i);
}

static void begin_a_new_text(const char* buffer, hps_uint32_t s, hps_uint32_t i) {
	assert(s <= i);
	print_buffer(buffer, s, i);
}

void hps_token(const char* buffer, hps_uint32_t length)
{
	assert(buffer != 0);
	assert(length > 0);

	hps_uint32_t i = 0;

	const hps_uint32_t state_text = 0; // normal state
	const hps_uint32_t state_on_tag = 1; // on tag state
	hps_uint32_t state = state_text;

	hps_uint32_t s = 0;

	for (i = 0; i < length; ++i) {
		char c = buffer[i];
		if ((state == state_text) && (c == '<')) {
			begin_a_new_tag(buffer, s, i);
			s = i;
			state = state_on_tag;
		} else if ((state == state_on_tag) && (c == '>')) {
			begin_a_new_text(buffer, s, i + 1);
			s = i + 1;
			state = state_text;
		}
	}

	print_buffer(buffer, s, length);
}
