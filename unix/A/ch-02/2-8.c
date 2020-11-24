#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd;

	fd = open("tmp.bbb", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1) {
		perror("Create tmp.bbb");
		exit(1);
	}

	dup2(fd, 1); // 파일 기술자 복사
	// oldfd, newfd - oldfd ->(copy) new fd
	printf("DUP2: Standard Ouput Redirection\n");
	close(fd);

	return 0;
}
