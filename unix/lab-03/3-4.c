#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd ,n;
	off_t start, cur;
	char buf[256];

	fd = open("3-1.txt", O_RDONLY);
	/* 저수준 파일 입출력을 이용해 3-1.txt를 open
           O_RDONLY: 파일을 읽기 전용으로 연다
	*/
	if (fd == -1) { // 파일 오픈 실패 
		perror("Open unix.txt"); // 에러 메시지 출력
		exit(1); // 시스템 종료
	}

	start = lseek(fd, 0, SEEK_CUR); // SEEK_CUR: 파일 현재 위치 기준에서 0만큼 오프셋 이동
	n = read(fd, buf, 255); // 파일에서 255만큼 바이트를 읽어서 buf에 저장
	buf[n] = '\0'; // 파일의 끝
	printf("Offset start=%d, Read Str=%s, n=%d\n", (int)start, buf, n);
	// 오프셋 시작위치, 읽어들인 파일의 내용, 파일의 크기 출력
	cur = lseek(fd, 0, SEEK_CUR); // 파일 현재 위치 기준에서 0만큼 오프셋 이동
	printf("Offset cur=%d\n", (int)cur); // 현재 오프셋 위치 출력

	start = lseek(fd, 7, SEEK_SET); // SEEK_SET: 파일의 시작을 기준으로 7만큼 오프셋 이동
	n = read(fd, buf, 255); // 파일에서 255만큼 바이트를 읽어서 buf에 저장
	buf[n] = '\0'; // 파일의 끝
	printf("Offset start=%d, Read Str=%s\n", (int)start, buf);	
	// 오프셋 시작 위치(파일 시작 기준에서 7만큼 오프셋 이동), 오프셋 시작 위치 부터 읽은 파일의 내용 출력
	
	close(fd); // 파일 닫기

	return 0;
}
