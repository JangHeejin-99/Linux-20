#include <unistd.h>
#include <stdio.h>

int main(void) {
	int i;

	for(i = 0; i < 10; i++) { // 10번 반복 
		printf("sleep 1 second...\n");
		sleep(1); // 1초 기다립니다.
	}
	return 0;
}
