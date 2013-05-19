#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "hps_log.h"

static void log_on_all_levels(void);

static int verbosity = 0;
static const char* logfile = "a.log";

static void my_log_func(int level, const char* message)
{
	if ((level & 0xFF) < verbosity)
	{
		return;
	}

	FILE *fp = stdout;

	if (logfile != 0)
	{
		fp = fopen(logfile, "a");
	}

	if (fp == 0)
	{
		return;
	}

	// get current time
	hps_char_t buf[64];
	time_t now = time(NULL);
	strftime(buf, sizeof(buf), "%d %b %H:%M:%S", localtime(&now));

	fprintf(fp, "[%d] %s - %s\n", (int)getpid(), buf, message);

	fflush(fp);

	if (logfile != 0)
	{
		fclose(fp);
	}
}

int main(int argc, char *argv[])
{
	hps_set_log_func(my_log_func);

	verbosity = HPS_DEBUG;
	log_on_all_levels();

	verbosity = HPS_INFO;
	log_on_all_levels();

	verbosity = HPS_NOTICE;
	log_on_all_levels();

	verbosity = HPS_WARNING;
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
