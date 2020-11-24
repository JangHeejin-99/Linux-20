#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

void handler(int signo) {
	psignal(signo, "Received Signal:");
	/* psignal(int sig(정보를 출력할 시그널), const char *s(출력할 문자열)) 
	-> s로 지정한 문자열을 출력 후 sig로 지정한 시그널을 가리키는 이름을 붙여 표준 오류 출력 */
	sleep(5); // 5초 기다림 
	printf("In Signal Handler, After Sleep\n");
}

int main(void) {
	struct sigaction act;

	sigemptyset(&act.sa_mask); 
	/* sa_mask에는 시그널 핸들러가 동작중일때 블록할 시그널을 시그널 집합으로 지정 
	시그널 집합을 비웠으므로(sigemptyset) 모든 시그널은 블록되지 않음 */
	act.sa_flags = 0; // 옵션 설정 X
	act.sa_handler = handler; 
	// sa_handler: 시그널에 대해 어떤 동작을 할 건지 설정
	if (sigaction(SIGINT, &act, (struct sigaction *)NULL) < 0) {
	/* sigaction(int sig(처리할 시그널)->SIGINT(프로세스 종료), 
	const struct sigaction *restrict act(시그널을 처리할 방법을 지정한 구조체 주소), 
	struct sigaction *restrict oact(기존에 시그널을 처리하던 방법을 저장할 구조체))
	*/
		perror("sigaction"); // error message 
		exit(1);
	}

	while(1) {
		fprintf(stderr, "Input SIGINT: ");
		// stderr : 표준 에러 출력장치 (보통은 모니터로 출력)
		pause(); // 신호가 전달될 때까지 무한정으로 sleep
		fprintf(stderr, "After Signal Handler\n");
	}
	return 0;
}

