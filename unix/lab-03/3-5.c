#include <stdlib.h>
#include <stdio.h>

int main(void) {
	FILE *rfp, *wfp;
	int c;

	if ((rfp = fopen("3-1.txt", "r")) == NULL) {
	/* 고수준 파일 입출력을 이용해 3-1.txt를 open
           r : 파일을 읽기 전용으로 연다  */
		perror("fopen: 3-1.txt"); // 파일 오픈 실패 시 에러메시지 출력
		exit(1); // 시스템 종료
	}

	if ((wfp = fopen("3-5.txt", "w")) == NULL) {
	/* 고수준 파일 입출력을 이용해 3-5.txt를 open
           w : 새로 쓰기용으로 텍스트 파일을 연다 */
		perror("fopen: 3-5.txt"); // 에러 메시지 출력
		exit(1);
	}
	
	while ((c = fgetc(rfp)) != EOF) { // rfp파일을 c에 문자 기반으로 입력한다 
		fputc(c, wfp); // wfp파일에 c를 문자 기반으로 출력해 작성한다
	}

	
	fclose(rfp); // 3-1.txt 파일 닫기
	fclose(wfp); // 3-3.txt 파일 닫기

	return 0;
}
