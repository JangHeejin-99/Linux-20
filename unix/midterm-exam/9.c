#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <wait.h>

int main(void) {
	pid_t p;
	char *a[3];
	int s;

	switch(p = fork()) {
		case -1: // fork failed
			perror("fork");
			exit(1);
			break;
		case 0: // child process
			printf("Child %d execute.\n", (int)getpid()); // 현재 process id를 읽음 
			a[0] = "ls";
			a[1] = "-a";
			a[2] = NULL;
			if (execv("/bin/ls", a) == -1) { // /bin/ls에서 a를 인자로 전달 
				perror("exec"); // 전달하지 못했으면 에러메시지 
				exit(3);
			}
		default: // parent process 
			printf("Parent %d is waiting for child's exit.\n", (int)getpid());
			// parent process의 id를 읽어 parent process id가 자식 프로세스의 종료를 기다리고 있음 
			wait(&s); // 리턴값: 자식 프로세스의 id -> 자식프로세스의 종료를 기다림 
	}
	printf("Child gave exit status %d to parent.\n", s>>8);
	// 오른쪽으로 8비트 이동해야 종료 상태값을 알 수 있음 -> 부모 프로세스 일 때 도달

	return 0;
}
