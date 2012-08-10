#include <stdio.h>
#include <assert.h>

#include "hps_util.h"
#include "hps_token.h"

static hps_int32_t create_a_tag(const char* buffer, hps_uint32_t s, hps_uint32_t i, hps_token_node* token)
{
	assert(s <= i);

	if (s == i) {
		return 0;
	}

	token->type = 1;
	token->content = buffer + s;
	token->length = i - s;

	return 1;
}

static hps_int32_t create_a_text(const char* buffer, hps_uint32_t s, hps_uint32_t i, hps_token_node* token)
{
	assert(s <= i);

	if (s == i) {
		return 0;
	}

	token->type = 0;
	token->content = buffer + s;
	token->length = i - s;

	return 1;
}

hps_uint32_t hps_token(const char* buffer, hps_uint32_t length, hps_token_node token_list[], hps_uint32_t token_list_length)
{
	assert(buffer != 0);
	assert(length > 0);

	assert(token_list != 0);
	assert(token_list_length > 0);

	hps_uint32_t i = 0;

	const hps_uint32_t state_text = 0; // normal state
	const hps_uint32_t state_on_tag = 1; // on tag state
	hps_uint32_t state = state_text;

	hps_uint32_t s = 0;

	hps_uint32_t token_index = 0;

	for (i = 0; i < length; ++i) {
		char c = buffer[i];
		if ((state == state_text) && (c == '<')) {
			if (token_index == token_list_length) {
				return 0;
			}
			if (1 == create_a_text(buffer, s, i, &token_list[token_index])) {
				// if return 1, then create text node successfully
				token_index++;
			}

			s = i;
			state = state_on_tag;
		} else if ((state == state_on_tag) && (c == '>')) {
			if (token_index == token_list_length) {
				return 0;
			}
			if (1 == create_a_tag(buffer, s, i + 1, &token_list[token_index])) {
				// if return 1, then create tag node successfully
				token_index++;
			}

			s = i + 1;
			state = state_text;
		}
	}

	if (token_index == token_list_length) {
		return 0;
	}

	if (1 == create_a_text(buffer, s, length, &token_list[token_index])) {
		// if return 1, then create text node successfully
		token_index++;
	}

	return token_index;
}
