#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
	char template[10] = "tempXXXXXX";
	char str[] = "3-7.c";
	int fname;
	// template에 /tmp/coredumpXXXXXX 복사
	fname = mkstemp(template);
	/* mkstemp: template의 파일을 고유 파일 이름으로 변환하고 
	   파일을 읽기/쓰기로 생성하고 생성된 파일 기술자를 반환한다. */
	// template매개변수는 문자 X가 6개로 끝나야한다
	write(fname, str, sizeof(str)-1);
	// str이 가리키는 메모리에서 str의 길이-1만큼 파일에 기록
	printf("%s\n", template);
	close(fname);

	return 0;
}
