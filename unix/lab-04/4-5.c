#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	if(mkdir("linux", 0755) == -1) {
	/* mkdir -> linux라는 디렉토리를 생성한다.
	(0755->rwxr-xr-x: 사용자는 읽기,쓰기,실행 권한, 
	그룹과 기타사용자는 읽기,실행 권한을 가진다.) */
		perror("linux"); // 생성 실패 시 에러 메시지 출력
		exit(1); // 실행 종료 
	}

	if(mkdir("programming", 0644) == -1) {
	/* mkdir -> programming이라는 디렉토리를 생성한다.
	(0644->rw-r--r--: 사용자는 읽기,쓰기 권한,
	그룹과 기타 사용자는 읽기권한을 가진다.) */
		perror("programming");// 생성 실패 시 에러 메시지 출력
		exit(1); // 실행 종료 
	}

	return 0;
}
