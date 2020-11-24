#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat buf; // 파일의 상태 및 정보를 저장할 buf 구조체 
	stat("password.txt", &buf);
	// inode에 저장된 파일 정보 검색
	// "password.txt"는 검색할 파일의 경로, 검색한 정보를 buf에 저장합니다.

	printf("mode before change = %o\n", (unsigned int)buf.st_mode);
	// 변하기 전 파일의 종류 및 접근 권한을 출력
		
	buf.st_mode |= S_IWGRP; // mode에 그룹 쓰기 권한을 추가(OR 연산 시 권한 추가)
	buf.st_mode &= ~(S_IROTH); // mode에 기타 사용자 읽기 권한을 제거(NOT연산 후 AND연산 시 권한 제거)
	chmod("password.txt", buf.st_mode); // password.txt의 mode를 변경
	stat("password.txt", &buf); // password.txt를 검색해 정보를 buf에 저장합니다.

	printf("mode after change = %o\n", (unsigned int)buf.st_mode);
	// 변경 후 파일의 종류 및 접근 권한을 출력 
	return 0;
}
