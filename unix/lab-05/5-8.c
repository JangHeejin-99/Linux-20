#include <sys/types.h>
#include <sys/times.h>
#include <limits.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int i;
	struct tms mytms;
	clock_t t1, t2;

	/* times(struct tms *buffer) = 사용자 실행시간과 시스템 실행시간으로 나누어
	tms 구조체에 저장 */
	if ((t1 = times(&mytms)) == -1) {
		perror("times 1"); // 에러 메시지 출력 
		exit(1);
	}

	for(i = 0; i <= 1000000; i++) // 사용자 모드에서 시간을 소비하기 위한 반복문 처리 
		printf("%d\n", i);

	if ((t2 = times(&mytms)) == -1) {
		perror("times 2"); // 에러 메시지 출력 
		exit(1);
	}

	/* limits.h -> #define CLK_TCK ((clock_t) _sysconf(3)) 
	= 3 is _SC_CLK_TCK(초당 클록 틱 수) */
	printf("Real time : %.5f sec\n", (double)(t2-t1) / sysconf(_SC_CLK_TCK)); // 경과시간 
	printf("User time : %.5f sec\n", (double)mytms.tms_utime / sysconf(_SC_CLK_TCK));
	// 사용자 수행시간 
	printf("System time : %.5f sec\n", (double)mytms.tms_stime / sysconf(_SC_CLK_TCK)); 
	// 시스템 수행시간 

	return 0;
}
