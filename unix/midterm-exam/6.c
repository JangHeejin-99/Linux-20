#include <time.h>
#include <locale.h>
#include <stdio.h>

int main(void) {
	struct tm *tm;
	// tm 구조체 
	time_t t; 
	char buf[257];

	setlocale(LC_ALL, "ko_KR.utf-8"); // 지역을 한국으로 설정 
	time(&t); // time: 초 단위로 현재 시간 정보 얻기 

	tm = localtime(&t); // localtime: 초 단위 시간 정보 분해 
	strftime(buf, sizeof(buf), "%G. %m. %d.",tm); 
	/* strftime: 출력 형식 기호 사용 
	(buf: 출력할 시간 정보를 저장할 배열 주소/ sizeof(buf): buf크기
	/ 출력형식/ tm: 출력할 시간 정보를 저장한 구조체 주소) */ 
	// %G: 년도(0000~9999), %m: 월(01~12), %d: 날짜(0~31)
	printf("%s ", buf);
	strftime(buf, sizeof(buf), "%a",tm); // %a: 지역 시간대의 요일명 약자 
	printf("(%s) ", buf); // 요일 출력 

	strftime(buf, sizeof(buf), "%H:%M:%S ",tm); 
	// %H: 24시간 기준 시간(00~23), %M: 분(00~59), %S: 초(00~60)
	printf("%s ", buf);
	strftime(buf, sizeof(buf), "%Z",tm); // %Z: timezone 명
	printf("%s\n", buf);

	return 0;
}
