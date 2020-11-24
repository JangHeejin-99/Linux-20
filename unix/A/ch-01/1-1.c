#include <unistd.h>
#include <errno.h>
#include <stdio.h>

extern int errno; // header file = errno.h

int main(void) {
	if (access("unix.txt", F_OK) == -1) {
		printf("errno=%d\n", errno);
	}

	return 0;
}
