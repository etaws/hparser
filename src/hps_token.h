#ifndef _HPARSER_TOKEN_H_
#define _HPARSER_TOKEN_H_

#include "hps_util.h"

typedef struct {
	hps_uint32_t type; // 0: text; 1: tag;
	const hps_char_t* content;
	hps_uint32_t length;
} hps_token_node;

// cut buffer into token nodes list
// return the length of token nodes list
extern hps_uint32_t hps_token(const char* buffer, hps_uint32_t length, hps_token_node token_list[], hps_uint32_t token_list_length);

extern hps_uint32_t hps_detect_tag_name(hps_token_node* tag_node);

#endif
