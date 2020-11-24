#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("PID: %d\n", (int)getpid()); // getpid: Process ID 검색 
	printf("PPID: %d\n", (int)getppid()); 
	// getppid: Parent Process ID 검색(부모프로세스 pid 리턴)
	
	return 0;
}
