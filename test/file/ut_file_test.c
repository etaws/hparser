#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hps_util.h"
#include "hps_file.h"
#include "hps_log.h"

static void print_buffer_bytes(hps_char_t* buffer, hps_uint32_t size);

int main(int argc, char *argv[])
{

	const hps_char_t* test_file_name = "hello";
	if (argc >= 2)
	{
		test_file_name = argv[1];
	}

	printf("test file name: %s\n", test_file_name);

	const hps_uint32_t BUFFER_SIZE = 1024 * 1024 * 100;
	void* buffer = hps_malloc(BUFFER_SIZE);

	if (buffer == 0)
	{
		return -1;
	}

	memset(buffer, 0, BUFFER_SIZE);

	hps_int32_t file_size = hps_read(test_file_name, buffer, BUFFER_SIZE);

	if (file_size > 0)
	{
		printf("success: %d\n", file_size);

		print_buffer_bytes((hps_char_t*) buffer, file_size);
	}
	else
	{
		printf("failed: %d\n", file_size);
	}

	free(buffer);
	buffer = 0;

	return 0;
}

void print_buffer_bytes(hps_char_t* buffer, hps_uint32_t size)
{
	for (hps_uint32_t i = 0; i < size; ++i)
	{
		printf("%d ", buffer[i]);
	}

	printf("\n");
}
