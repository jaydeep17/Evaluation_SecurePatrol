/*
 * This file is used for benchmarking without using GOT protector
 * in Secure Patrol
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("This program requires 1 argument.\n");
		printf("./executable <iterations>\n");
		return 0;
	}

	int i;
	for (i = 0; i < atoi(argv[1]); ++i) {
		printf("printf before attack - - -\n");
	}

	return 0;
} 