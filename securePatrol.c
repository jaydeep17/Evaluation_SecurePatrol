#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stackLib.c"

__thread struct Stack *ptr;
int *securePointer = 0;

void func(const char *msg) {
	char buffer[10];
	
	/*
	 * Stack Patrol prologue
	 */
	securePointer = &buffer;
	securePointer = (char*)securePointer + 10 /* size of buffer */ + 20 /* by doing this securePointer points to RET */;
	stackPush(ptr,*securePointer);

	/*
	 * Function code
	 */
//	printf("sp = %p\n", securePointer);
	strcpy(buffer,msg);
//	printf("garbage\n");


	/*
	 * Stack Patrol epilogue
	 */
	int ret = stackPop(ptr);
	int secValue = (*securePointer);
	if(ret != secValue) {
		printf("You are a victim of buffer overflow\n");
		exit(0);
	}
}

int main(int argc, char const *argv[]) {

	if (argc != 3) {
		printf("This program requires 2 arguments.\n");
		printf("./executable <string> <iterations>\n");
		return 0;
	}

	/*
	 * Code to run when program starts
	 */
	if(ptr == 0) {
        ptr = malloc(sizeof *ptr);
    }
	stackInit(ptr);


	/*
	 * program code
	 */
	int i;
	for (i = 0; i < atoi(argv[2]); ++i)
		func(argv[1]);
	return 0;
}
