#include <stdio.h>
#include <string.h>

#include "hps_token.h"

int main(int argc, char *argv[])
{
//	const char* b0 = "";
//	hps_token(b0, strlen(b0));

	const char* b1 = "<>";
	hps_token(b1, strlen(b1));
	printf("=====\n");

	const char* b2 = "<tttt>";
	hps_token(b2, strlen(b2));
	printf("=====\n");

	const char* b3 = "a";
	hps_token(b3, strlen(b3));
	printf("=====\n");

	const char* b4 = "<tttt>a.log";
	hps_token(b4, strlen(b4));
	printf("=====\n");

	const char* b5 = "b<tttt>a.log";
	hps_token(b5, strlen(b5));
	printf("=====\n");

	b5 = "b<tttt>";
	hps_token(b5, strlen(b5));
	printf("=====\n");

	b5 = "b<>";
	hps_token(b5, strlen(b5));
	printf("=====\n");

	b5 = "b<>>";
	hps_token(b5, strlen(b5));
	printf("=====\n");

	b5 = "<><>";
	hps_token(b5, strlen(b5));
	printf("=====\n");

	return 0;
}
