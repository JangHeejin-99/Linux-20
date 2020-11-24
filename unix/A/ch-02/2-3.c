#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd;
	
	close(0);

	fd = open("unix.txt", O_RDWR); // O_RDWR: 파일 읽기,쓰기 가능 
	if (fd == -1) {
		perror("RDWR");
		exit(1);
	}

	printf("unix.txt : fd = %d\n", fd);
	close(fd);

	return 0;
}
