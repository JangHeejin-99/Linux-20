#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *fp;
	char buf[256];

	fp = popen("ps","r"); // 자식 프로세스는 ps명령 실행(ps -> 프로세스 목록 출력)
	// 파이프 생성(popen(command(쉘 명령), mode(r: 읽기 전용, w: 쓰기전용)))
	if (fp == NULL) {
		fprintf(stderr, "popen failed\n");
		exit(1);
	}

	if (fgets(buf, sizeof(buf), fp) == NULL) { // 파이프에서 데이터 읽기 
		fprintf(stderr, "No data frome pipe!\n");
		exit(1);
	}

	printf("%s", buf);
	system("ps -f"); // ps -f를 실행하는 코드 
	// ps -f: 프로세스를 full format으로 출력 
	pclose(fp);

	return 0;
}
