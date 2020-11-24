#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

int main(void) {
	printf("Before SIGCONT Signal to parent.\n");

	kill(getppid(), SIGCONT); // kill: 지정된 프로세스에 지정한 시그널을 보냄 
	/* getppid(): parent process id를 가져옴 
	   sigcont: continue(stop이나 tstp에 의해 정지된 프로세스가 다시 실행을 계속함)
	   -> parent process 실행을 계속함 
	*/
	printf("Before SIGQUIT Signal to me.\n");

	kill(getpid(), SIGQUIT);
	/* getpid(): process id를 가져옴 
	   sigquit: quit(실행 종료, ctrl+c를 입력할때 보내짐) 
	   -> process의 실행을 종료함 
	*/
	   
	printf("After SIGQUIT Signal.\n");

	return 0;
}
