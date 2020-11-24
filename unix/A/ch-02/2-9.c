#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd, flags;
	fd = open("unix.txt", O_RDWR);
	if(fd == -1) {
		perror("Open");
		exit(1);
	}
	if ((flags = fcntl(fd, F_GETFL)) == -1) { // fcntl: 파일 기술자 제어
	// F_GETFL: 상태 플래그 정보를 읽어온다.
		perror("fcntl");
		exit(1);
	}

	flags|= O_APPEND; // O_APPEND: 파일의 맨 끝에 내용 추가

	if (fcntl(fd, F_SETFL, flags) == -1) {
	// F_SETFL : 상태 플래그 정보를 설정한다.
		perror("fcntl");
		exit(1);
	}

	if(write(fd, "Hanbit Media", 12) != 12)
		perror("write");

	close(fd);

	return 0;
}
