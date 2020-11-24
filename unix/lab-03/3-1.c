#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int fd;
	mode_t mode;

	mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	/* mode(파일 접근 권한 지정)
	 -> S_IRUSR(소유자 읽기 권한) | S_IWUSR(소유자 쓰기 권한)
	 | S_IRGRP(그룹 읽기 권한) | S_IROTH(기타 사용자 읽기 권한)
	*/
	fd = open("3-1.txt", O_CREAT, mode);
	/* 저수준 파일 입출력을 이용해 3-1.txt를 open
           O_CREAT: 파일이 없으면 파일 생성, mode: mode 지정
	*/
	if (fd == -1) { // 파일 오픈 실패 
		perror("Creat"); // 에러 메시지 출력
		exit(1); // 시스템 종료
	}

	close(fd); // 파일 닫기

	return 0;
}
