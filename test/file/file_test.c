#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hps_util.h"
#include "hps_file.h"
#include "hps_log.h"

static void print_buffer_bytes(hps_char_t* buffer, hps_uint32_t size);
static void print_v_buffer(hps_char_t* buffer, hps_uint32_t size);
static void print_hex(int i);

int main(int argc, char *argv[])
{
	hps_set_log_file("a.log");

	hps_set_log_level(HPS_DEBUG);

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
	hps_char_t sixteen[16];
	memset(sixteen, 0, sizeof(sixteen));
	hps_uint32_t j = 0;

	hps_uint32_t end = size;
	if ((size % 16) != 0)
	{
		end = size + 16 - (size % 16);
	}

	for (hps_uint32_t i = 0; i < end; ++i)
	{
		if (i < size)
		{
			sixteen[j] = buffer[i];
			print_hex(buffer[i]);
		}
		else
		{
			sixteen[j] = 0;
			printf("  ");
		}

		if (i % 16 == 15)
		{
			printf("  ");
			print_v_buffer(sixteen, sizeof(sixteen));
			j = 0;
		}
		else if ((i % 2) == 1)
		{
			j++;
			printf(" ");
		}
		else
		{
			j++;
		}
	}
}

void print_v_buffer(hps_char_t* buffer, hps_uint32_t size)
{
	for (hps_uint32_t i = 0; i < size; ++i)
	{
		int c = buffer[i];
		if ((c >= 20) && (c <= 127))
		{
			printf("%c", buffer[i]);
		}
		else if (buffer[i] != 0)
		{
			printf(".");
		}
		else
		{
		}

		buffer[i] = 0;
	}

	printf("\n");
}

void print_hex(int i)
{
	if (i > 15)
	{
		printf("%x", i);
	}
	else
	{
		printf("0%x", i);
	}
}
