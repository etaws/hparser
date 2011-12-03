#include <stdlib.h>

#include "hps_util.h"

void* hps_malloc(hps_uint32_t size)
{
	return malloc(size);
}
