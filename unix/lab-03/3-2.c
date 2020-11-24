#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	int fd;
	int n;

	char str[] = "UNIX SYSTEM PROGRAMMING";

	fd = open("3-1.txt", O_WRONLY);
	/* 저수준 파일 입출력을 이용해 3-1.txt를 open
           O_WRONLY: 파일을 쓰기 전용으로 연다
	*/
	if (fd == -1) { // 파일 오픈 실패 
		perror("Open"); // 에러 메시지 출력
		exit(1); // 시스템 종료
	}

	n = write(fd, str, strlen(str));
	/* str이 가리키는 메모리에서 str의 길이만큼 파일(fd)에 기록한다 
	-> 실제로 쓰기를 수행한 바이트 수를 리턴한다 */
	if (n != strlen(str)) { // 쓰기 실패
		perror("Write"); // 에러 메시지 출력
		exit(2);
	}

	close(fd); // 파일 닫기

	return 0;
}
