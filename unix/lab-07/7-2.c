#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) {
	int pd[2]; // pd[0]: 읽기, pd[1]: 쓰기용 파일 기술자 
	char str[] = "Pipe Test";
	char buf[256];
	int len, status;

	if (pipe(pd) == -1) { // pipe: 파이프 만들기 
		perror("pipe");
		exit(1);
	}

	write(pd[1], str, strlen(str)); // pd[1]에 str의 내용을 씀  
	printf("Process %d writes %s to pipe.\n", (int)getpid(), str);
	// process id가 pipe에 str 내용을 쓰고있다고 출력 
	len = read(pd[0], buf, 256); // 파이프에서 읽음 
	buf[len] = '\0'; // buf의 마지막임을 뜻함 
	printf("Process %d reads %s from pipe.\n", (int)getpid(), buf);
	// process id가 pipe로부터 buf 내용을 읽고있다고 출력 

	close(pd[0]);
	close(pd[1]);

	return 0;
}

