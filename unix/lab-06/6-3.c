#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void) {
	int i;

	signal(SIGINT, SIG_IGN); // SIG_IGN: 시그널을 무시합니다.
	// SIGINT: 프로세스의 기본 행동은 종료  
	/* signal(int signum(제어할 시그널 번호),
	 sighandler_t handler(signum을 받았을 때 호출할 함수) */ 
	for(i = 0; i < 10; i++) { // 10번 반복 
		printf("sleep 1 second...\n");
		sleep(1); // 1초 기다림 
	}
	return 0;
}
