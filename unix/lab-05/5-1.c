#include <unistd.h>
#include <stdio.h>

int main(void) {
	printf("Max argv and envp : %ld\n", sysconf(_SC_ARG_MAX));
	// _SC_ARG_MAX: argv[]와 envp[]를 합한 최대 크기, 바이트 단위
	printf("Max child : %ld\n", sysconf(_SC_CHILD_MAX));
	// _SC_CHILD_MAX: 한 UID에 허용되는 최대 프로세스 개수 
	printf("Clock Tick : %ld\n", sysconf(_SC_CLK_TCK));
	// _SC_CLK_TCK: 초당 클록 틱 수 
	printf("Max Open File : %ld\n", sysconf(_SC_OPEN_MAX));
	// _SC_OPEN_MAX: 프로세스당 열 수 있는 최대 파일 개수 
	printf("Version : %ld\n", sysconf(_SC_VERSION));
	// _SC_VERSION: 시스템이 지원하는 POSIX.1의 버전 
	
	return 0;
}
