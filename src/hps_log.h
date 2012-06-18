#ifndef _HPARSER_LOG_H_
#define _HPARSER_LOG_H_

#include "hps_util.h"

#define HPS_DEBUG 1
#define HPS_INFO 2
#define HPS_NOTICE 3
#define HPS_WARNING 4

extern void hps_set_log_level(hps_uint32_t level);
extern void hps_set_log_file(const hps_char_t* filename);

extern void hps_log(hps_uint32_t level, const hps_char_t* message);

#endif
