#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>

extern int errno; // header file = errno.h

int main(void) {
	FILE *fp;

	if ((fp = fopen("unix.txt", "r")) == NULL) {
		printf("errno=%d\n", errno);
		exit(1);
	}

	return 0;
}
