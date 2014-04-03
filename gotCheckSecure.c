/*
 * This file is used for benchmarking of GOT protector
 * in Secure Patrol
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// global array
unsigned shadowGOT[1];

// enum definition for better readability
enum gotMAPPING
{
	__printf
};

int main(int argc, char **argv) {
	if (argc != 2) {
		printf("This program requires 1 argument.\n");
		printf("./executable <iterations>\n");
		return 0;
	}

	// initialization
	int *printfPointer = &printf + 0x2;
	shadowGOT[__printf] = *printfPointer;


	int i;
	for (i = 0; i < atoi(argv[1]); ++i) {
		// every printf call will be checked
		if (*printfPointer == shadowGOT[__printf]) {
			printf("printf before attack - - -\n");
		} else {
			exit(-1);
		}
	}

	return 0;
} 