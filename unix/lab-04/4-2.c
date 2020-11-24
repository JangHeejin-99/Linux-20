#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat buf; // 파일의 상태 및 정보를 저장할 buf 구조체 
	stat("password.txt", &buf);
	// inode에 저장된 파일 정보 검색
	// "password.txt"는 검색할 파일의 경로, 검색한 정보를 buf에 저장합니다.

	printf("Mode = %o (16진수: %x)\n", (unsigned int)buf.st_mode, (unsigned int)buf.st_mode);
	// 파일의 종류 및 접근 권한을 출력
		
	// 매크로를 이용한 파일의 종류 검색
	if(S_ISFIFO(buf.st_mode)) // S_ISFIFO(mode)이 참이면 FIFO 파일 
		printf("password.txt: FIFO\n");
	if(S_ISDIR(buf.st_mode)) // S_ISDIR(mode)이 참이면 디렉토리 파일 
		printf("password.txt: Directory\n");
	if(S_ISREG(buf.st_mode)) // S_ISREG(mode)이 참이면 일반 파일 
		printf("password.txt: Regular File\n");

	return 0;
}
