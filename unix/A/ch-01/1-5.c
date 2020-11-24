#include <sys/errno.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern int errno;

int main(void) {
	char *err;

	if (access("unix.txt", R_OK) == -1) {
		err = strerror(errno); // perror과 다르게 자신이 원하는 곳으로 옮길 수 있음
		printf("오류: %s(unix.txt)\n", err);
		exit(1);
	}

	return 0;
}
