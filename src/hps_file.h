#ifndef _HPARSER_FILE_H_
#define _HPARSER_FILE_H_

#include "hps_util.h"

/*
 * read the file content into buffer. if failed, return -1, else return the
 * size of this file
 */
extern hps_int32_t hps_read(const hps_char_t* file_name, void* buffer, hps_uint32_t buffer_size);

#endif
