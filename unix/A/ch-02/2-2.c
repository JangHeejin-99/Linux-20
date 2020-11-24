#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd;

	fd = open("unix.txt", O_CREAT | O_EXCL, 0644); // 0644 = 일반 파일 
	// O_EXCL: O_CREAT와 함께 사용할 경우 기존에 없으면 파일 생성, 파일이 있으면 파일 생성X 오류메시지 출력 
	if (fd == -1) {
		perror("Excl");
		exit(1);
	}
	close(fd);

	return 0;
}
