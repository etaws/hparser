#include <stdio.h>

#include "hps_log.h"

static hps_log_func using_log_func = 0;

void hps_set_log_func(hps_log_func func)
{
	using_log_func = func;
}

void hps_log(hps_uint32_t level, const hps_char_t* message)
{
	if (using_log_func == 0)
	{
		printf("%s\n", message);
		return;
	}

	(*using_log_func)(level, message);
}
