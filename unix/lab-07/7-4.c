#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	int pd1[2], pd2[2]; // 파이프 2개를 생성하기위해 배열2개 선언 
	pid_t pid;
	char buf[BUFSIZ];
	int len, status;

	if (pipe(pd1) == -1) { // pipe: 파이프 만들기 
		perror("pipe");
		exit(1);
	}
	if (pipe(pd2) == -1) { // pipe: 파이프 만들기 
		perror("pipe");
		exit(1);
	}

	switch(pid = fork()) { // fork로 자식프로세스 생성 
		case -1:
			perror("fork");
			exit(1);
			break;
		case 0: // child->pd1[0]으로 읽기, pd2[1]로 쓰기 
			close(pd1[1]); // pd1[1](쓰기용) 닫기 
			close(pd2[0]); // pd2[0](읽기용) 닫기 
			
			write(1, "child process:", 15);
			len = read(pd1[0], buf, BUFSIZ); // pd1[0]으로 파이프에서 buf 내용을 읽음 
			write(1, buf, len); // stdout(1)으로 출력 

			strcpy(buf, "from child\n"); 
			write(pd2[1], buf, strlen(buf)); // pd2[1]으로 buf 내용을 씀 
			// child는 parent에게 from child를 write 
			break;
		default: // parent->pd1[1]으로 쓰기, pd2[0]로 읽기 
			close(pd1[0]); // pd1[0](읽기용) 닫기
			close(pd2[1]); // pd2[1](쓰기용) 닫기
			buf[0] = '\0';
			write(pd1[1], "from parent\n", 12); 
			// 파이프에 "from parent"의 내용을 씀  
			
			waitpid(pid, &status, 0); // 자식 프로세스가 끝날때까지 기다림 
			write(1, "parent process:", 15);
			len = read(pd2[0], buf, BUFSIZ); // pd2[0]을 이용해 파이프에서 buf 내용을 읽음 
			write(1, buf, len); // stdout(1)으로 출력 
			
			break;
	}

	return 0;
}

