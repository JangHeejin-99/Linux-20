#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	if(rename("linux", "LINUX") == -1) {
	// rename -> linux라는 디렉토리의 이름을 LINUX로 변경한다.
		perror("Rename"); // 변경 실패 시 에러 메시지 출력
		exit(1); // 실행 종료 
	}

	return 0;
}
