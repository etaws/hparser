#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

#include "hps_log.h"
#include "hps_file.h"

static hps_uint32_t get_size_of_file(const hps_char_t* file_name);

hps_int32_t hps_read(const hps_char_t* file_name, void* buffer, hps_uint32_t buffer_size)
{
	assert(buffer != 0);
	assert(buffer_size > 0);

	hps_uint32_t file_size = get_size_of_file(file_name);

	/*
	 * the max size of file is 100M
	 */
	const hps_uint32_t MAX_SIZE_OF_FILE = 100 * 1024 * 1024;

	if ((file_size == 0) || (file_size > MAX_SIZE_OF_FILE))
	{
		hps_log(HPS_INFO, "file is too large");
		return -1;
	}

	if (file_size >= buffer_size)
	{
		hps_log(HPS_INFO, "file is large than the buffer");
		return -1;
	}

	int fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		hps_log(HPS_INFO, "failed to open file");
		return -1;
	}

	ssize_t read_bytes = read(fd, buffer, file_size);
	if (read_bytes <= 0)
	{
		hps_log(HPS_INFO, "failed to read file");
		close(fd);
		return -1;
	}

	close(fd);

	return file_size;
}

/*
 * if failed to get the file size, return 0;
 */
hps_uint32_t get_size_of_file(const hps_char_t* file_name)
{
	assert(0 != file_name);

	struct stat buf;
	memset((void*)&buf, 0, sizeof(buf));

	if (stat(file_name, &buf) < 0)
	{
		return 0;
	}

	return (hps_uint32_t) buf.st_size;
}

