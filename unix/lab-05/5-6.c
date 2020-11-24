#include <stdio.h>

int main(void) {
	int i;
	long s = 0;

	for(i = 0; i <= 1000000; i++) // 0~1000000까지 s에 값 더하기 
		s = s + i;

	printf("%ld\n", s); // 출력

	return 0;
}
