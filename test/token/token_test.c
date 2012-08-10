#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hps_token.h"

static void print_buffer(const char* buffer, hps_uint32_t length) {
	assert(length != 0);

	hps_uint32_t i = 0;
	for (; i < length; ++i) {
		printf("%c", buffer[i]);
	}
	printf("\n");
}

static void print_token_list(hps_token_node* list, hps_uint32_t length)
{
	for (hps_uint32_t i = 0; i < length; ++i) {
		const hps_char_t* s = list[i].content;
		hps_uint32_t l = list[i].length;

		printf("%d ", list[i].type);
		print_buffer(s, l);
	}
}

int main(int argc, char *argv[])
{
//	const char* b0 = "";
//	hps_token(b0, strlen(b0));

	const hps_uint32_t node_list_size = 3;
	hps_token_node* node_list = malloc(node_list_size * sizeof(hps_token_node));
	memset(node_list, 0, node_list_size * sizeof(hps_token_node));

	const char* b1 = "<>";
	hps_uint32_t r = 0;
	r = hps_token(b1, strlen(b1), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	const char* b2 = "<tttt>";
	r = hps_token(b2, strlen(b2), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	const char* b3 = "a";
	r = hps_token(b3, strlen(b3), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	const char* b4 = "<tttt>a.log";
	r = hps_token(b4, strlen(b4), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	const char* b5 = "b<tttt>a.log";
	r = hps_token(b5, strlen(b5), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	b5 = "b<tttt>";
	r = hps_token(b5, strlen(b5), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	b5 = "b<>";
	print_token_list(node_list, r);
	r = hps_token(b5, strlen(b5), node_list, node_list_size);
	printf("=====\n");

	b5 = "b<>>";
	print_token_list(node_list, r);
	r = hps_token(b5, strlen(b5), node_list, node_list_size);
	printf("=====\n");

	b5 = "<><>";
	r = hps_token(b5, strlen(b5), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	b5 = "<><><><>";
	r = hps_token(b5, strlen(b5), node_list, node_list_size);
	print_token_list(node_list, r);
	printf("=====\n");

	free(node_list);
	node_list = 0;

	return 0;
}
