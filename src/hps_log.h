#ifndef _HPARSER_LOG_H_
#define _HPARSER_LOG_H_

const int HPS_DEBUG = 1;
const int HPS_INFO = 2;
const int HPS_NOTICE = 3;
const int HPS_WARNING = 4;

extern void hps_set_log_level(int level);
extern void hps_set_log_file(const char* filename);

extern void hps_log(int level, const char* message);

#endif
