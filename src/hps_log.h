#ifndef _HPARSER_LOG_H_
#define _HPARSER_LOG_H_

#include "hps_util.h"

#define HPS_DEBUG 1
#define HPS_INFO 2
#define HPS_NOTICE 3
#define HPS_WARNING 4

typedef void (*hps_log_func)(int level, const char* message);

extern void hps_set_log_func(hps_log_func func);

extern void hps_log(hps_uint32_t level, const hps_char_t* message);

#endif
