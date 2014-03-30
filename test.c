#include <stdio.h>
#include <string.h>

void func(const char *a) {
	char buffer[10];
	strcpy(buffer, a);
}

int main(int argc, char *argv[]) {

	int i;
	for (i = 0; i < 1000000; ++i) {
		func(argv[1]);
	}

}