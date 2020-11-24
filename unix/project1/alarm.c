#include <stdio.h>
#include <time.h>


int main(void) {

	struct tm* tm; // tm 구조체 
	time_t t;  // 시간 
	FILE *fp; // 알람을 읽고 쓸 파일 
	int hour, min; // 사용자에게 받고 알람에 쓸 시간
	char buf[256]; // 알람 내용 
	char mode; // 알람 설정 여부 변수 
	

	fp = fopen("alarm.txt", "a+");	// alarm.txt를 열어 파일 끝에 값을 이어 쓰고, 파일이 없으면 파일을 생성합니다.

	printf("=========알람 프로그램=========\n");
	printf("알람을 설정하시겠습니까?(y/n)"); 
	scanf("%c", &mode); // 알람 설정 여부 입력 


	if (mode == 'y') {
		printf("알람 설정(시 분 내용): "); 
		scanf("%d %d %s", &hour, &min, buf); // 시간 분 내용 입력 
		fprintf(fp, "%d %d %s\n", hour, min, buf); // 파일에 시, 분, 내용 출력 
	
		fscanf(fp, "%d %d %s\n", &hour, &min, buf); // 파일에서 시, 분, 내용을 읽어옴

		while(1) {
			time(&t); // 초 단위로 현재 시간 정보 얻기 
			tm = localtime(&t); // 지역 시간대 기준으로 시간 정보를 분해 
			if (hour == tm->tm_hour && min == tm->tm_min && tm->tm_sec == 0) { // 설정한 시간이 되면 
				printf("%s\n", buf); // 알람 내용 출력 
				break; // 종료 
			}
		}	
	}


	return 0;
}
