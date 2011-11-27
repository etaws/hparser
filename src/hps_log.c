#include <time.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include "hps_log.h"

static int verbosity = HPS_INFO;
static const char* logfile = 0;

void hps_set_log_level(int level)
{
	verbosity = level;
}

void hps_set_log_file(const char* filename)
{
	logfile = filename;
}

void hps_log(int level, const char* message)
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


    char buf[64];
	time_t now = time(NULL);
	strftime(buf, sizeof(buf), "%d %b %H:%M:%S", localtime(&now));
	fprintf(fp, "[%d] %s - %s\n", (int)getpid(), buf, message);

    fflush(fp);

	if (logfile != 0)
	{
		fclose(fp);
	}
}
