#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	DIR *dp;
	struct dirent *dent;

	if ((dp = opendir(".")) == NULL) {
	/* opendir: 성공하면 열린 디렉토리를 가리키는 DIR 포인터를 리턴 
	   -> .디렉토리(현재 디렉토리)를 연다 */
		perror("opendir: ."); // 실패 시 에러 메세지 출력 
		exit(1); // 실행 종료 
	}

	while ((dent = readdir(dp))) {	
	// 디렉토리 dp(현재 디렉토리)의 내용을 한 번에 하나씩 읽어옴 
		printf("Name : %s  ", dent->d_name); // 디렉토리의 이름 출력 
		printf("Inode : %d\n", (int)dent->d_ino); // 디렉토리의 inode 출력
	}

	closedir(dp); // 디렉토리 닫기 

	return 0;
}
