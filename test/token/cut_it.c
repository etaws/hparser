#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "hps_token.h"
#include "hps_util.h"
#include "hps_file.h"

static void print_token_list(hps_token_node* list, hps_uint32_t length);

int main(int argc, char* argv[])
{
	// get the file name from parameter
	const hps_char_t* test_file_name = "c.html";
	if (argc >= 2) {
		test_file_name = argv[1];
	}

	printf("test file name: %s\n", test_file_name);

	// prepare the buffer for the file content
	const hps_uint32_t BUFFER_SIZE = 1024 * 1024 * 100;
	void* buffer = hps_malloc(BUFFER_SIZE);
	if (buffer == 0) {
		return -1;
	}

	memset(buffer, 0, BUFFER_SIZE);

	// read file
	hps_int32_t file_size = hps_read(test_file_name, buffer, BUFFER_SIZE);
	if (file_size <= 0) {
		printf("failed: %d\n", file_size);
		return 0;
	}
	printf("file size: %d\n", file_size);

	// prepare the nodes list
	const hps_uint32_t node_list_size = 1024 * 1024;
	hps_token_node* node_list = malloc(node_list_size * sizeof(hps_token_node));
	memset(node_list, 0, node_list_size * sizeof(hps_token_node));

	// cut the file content into the nodes list
	hps_uint32_t r = hps_token(buffer, file_size, node_list, node_list_size);

	printf("node number: %d\n", r);
	print_token_list(node_list, r);

	free(node_list);
	node_list = 0;

	free(buffer);
	buffer = 0;

	return 0;
}

static void print_buffer(const char* buffer, hps_uint32_t length)
{
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
		hps_uint32_t ll = hps_detect_tag_name(&list[i]);
		if (ll > 0) {
			print_buffer(list[i].content, ll);
		}
		print_buffer(s, l);
	}
}
