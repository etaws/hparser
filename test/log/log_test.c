#include <stdio.h>

#include "hps_log.h"

static void log_on_all_levels(void);

int main(int argc, char *argv[])
{
	hps_set_log_file("a.log");

	hps_set_log_level(HPS_DEBUG);
	log_on_all_levels();

	hps_set_log_level(HPS_INFO);
	log_on_all_levels();

	hps_set_log_level(HPS_NOTICE);
	log_on_all_levels();

	hps_set_log_level(HPS_WARNING);
	log_on_all_levels();

	printf("test end.\n");

	return 0;
}

void log_on_all_levels(void)
{
	hps_log(HPS_DEBUG, "debug it");
	hps_log(HPS_INFO, "info it");
	hps_log(HPS_NOTICE, "notic it");
	hps_log(HPS_WARNING, "warning it");
	hps_log(HPS_WARNING, "========================");
}
