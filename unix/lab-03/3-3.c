#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int rfd, wfd, n;

	char buf[BUFSIZ];

	rfd = open("3-1.txt", O_RDONLY);
	/* 저수준 파일 입출력을 이용해 3-1.txt를 open
           O_RDONLY: 파일을 읽기 전용으로 연다
	*/
	if (rfd == -1) { // 파일 오픈 실패 
		perror("Open 3-1.txt"); // 에러 메시지 출력
		exit(1); // 시스템 종료
	}

	wfd = open("3-3.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	/* 저수준 파일 입출력을 이용해 3-3.txt를 open
           O_CREAT(파일이 없으면 파일 생성) | O_WRONLY(파일을 쓰기 전용으로 연다) 
	   | O_TRUNC(파일 생성 시 이미 있는 파일이고 쓰기 옵션으로 열었으면 내용을 모두 지우고 
		파일의 길이를 0으로 변경)
	   , mode : 0644=소유자 읽기, 쓰기 권한 + 그룹 읽기 권한 + 기타 사용자 읽기 권한
	*/
	if (wfd == -1) { // 파일 오픈 실패
		perror("Open 3-3.txt"); // 에러 메시지 출력
		exit(1);
	}

	while ((n = read(rfd, buf, sizeof(buf))) > 0) { // 파일에서 buf 크기 만큼 바이트를 읽어서 buf에 저장
		if (write(wfd, buf, n) != n) // buf가 가리키는 메모리에서 n만큼 파일에 기록
			perror("Write"); // 쓰기 실패 시 에러 메시지 출력
	}

	if (n == -1) // 파일 읽기 실패 시 
		perror("Read"); // 에러 메시지 출력

	close(rfd); // 3-1.txt 파일 닫기
	close(wfd); // 3-3.txt 파일 닫기

	return 0;
}
