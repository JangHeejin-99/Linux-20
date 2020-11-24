#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	if(rmdir("programming") == -1) {
	// rmdir -> programming라는 디렉토리를 삭제한다.
		perror("Rename"); // 삭제 실패 시 에러 메시지 출력
		exit(1); // 실행 종료 
	}

	return 0;
}
