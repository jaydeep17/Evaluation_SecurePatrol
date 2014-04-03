#include <stdio.h>
#include <string.h>

void func(const char *a) {
	char buffer[10];
	strcpy(buffer, a);
}

int main(int argc, char *argv[]) {
	if (argc != 3) {
		printf("This program requires 2 arguments.\n");
		printf("./executable <string> <iterations>\n");
		return 0;
	}
	int i;
	for (i = 0; i < atoi(argv[2]); ++i) {
		func(argv[1]);
	}

}