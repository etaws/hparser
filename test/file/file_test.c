#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file.h"

void print_buffer_bytes(char* buffer, size_t size);

int main(int argc, char *argv[])
{
	const char* test_file_name = "hello";
	if (argc >= 2)
	{
		test_file_name = argv[1];
	}

	printf("test file name: %s\n", test_file_name);

	const int BUFFER_SIZE = 1024 * 1024 * 100;
	void* buffer = malloc(BUFFER_SIZE);
	if (buffer == 0)
	{
		return -1;
	}

	memset(buffer, 0, BUFFER_SIZE);

	int file_size = read(test_file_name, buffer, BUFFER_SIZE);

	if (file_size > 0)
	{
		printf("success: %d\n", file_size);

		print_buffer_bytes((char*)buffer, file_size);
	}
	else
	{
		printf("failed: %d\n", file_size);
	}

	free(buffer);
	buffer = 0;

	return 0;
}

void print_buffer_bytes(char* buffer, size_t size)
{
	for (size_t i = 0; i < size; ++i)
	{
		printf("%d ", buffer[i]);
	}

	printf("\n");
}
