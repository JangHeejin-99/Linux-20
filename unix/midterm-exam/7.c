#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char name[10]; // 학생 이름
	int s1; // 점수1
	int s2; // 점수2
	int s3; // 점수3
	int sum; // 각 학생 점수 총 합
	double result; // 각 학생 과목 평균
}stud;

int compare(const void *a, const void *b) { // qsort를 위한 비교 함수
	const stud *m = (const stud *)a;
	const stud *n = (const stud *)b;
	return n->sum - m->sum;

}

int main(void) {
	FILE *rfp, *wfp;
	stud s[5];
	int n;
	int sum1=0, sum2=0, sum3=0; // 점수1, 점수2, 점수3 총 합
	double result1=0, result2=0, result3=0; // 점수1, 점수2, 점수3 평균
	int i = 0;

	if ((rfp = fopen("7.dat", "r")) == NULL) { // 3-8.dat을 읽기 모드로 open
		perror("fopen: 7.dat"); // 에러 메시지 출력
		exit(1);
	}

	if ((wfp = fopen("7.out", "w")) == NULL) { // 3-8.out를 쓰기 모드로 open
		perror("fopen: 7.out"); // 에러 메시지 출력
		exit(1);
	}
	while((n = fscanf(rfp, "%s %d %d %d", s[i].name, &s[i].s1, &s[i].s2, &s[i].s3)) != EOF) {
	// 이름과 점수1, 점수2, 점수3을 7.dat에서 읽어들임 (파일의 끝까지)
		s[i].sum = s[i].s1 + s[i].s2 + s[i].s3; // 각 학생의 합
		s[i].result = s[i].sum / 3; // 각 학생의 평균
		sum1 += s[i].s1; sum2 += s[i].s2; sum3 += s[i].s3; // 점수1, 점수2, 점수3 별 총 합
		result1 = sum1/3; result2 = sum2/3; result3 = sum3/3; // 점수1, 점수2, 점수3 별 평균
		i++;
	}

	printf("7.dat의 내용\n");
	for(i = 0; i < 5; i++) {
		printf("\t%5s %3d %3d %3d\n", s[i].name, s[i].s1, s[i].s2, s[i].s3);
	}

	qsort(s, 5, sizeof(s[0]), compare); 
	//qsort 함수(정렬할 배열, 정렬할 원소 개수, 원소 하나의 크기, 비교 알고리즘)

	fseek(rfp, 0, SEEK_SET); // 7.dat의 오프셋 위치를 처음으로 되돌림

	fprintf(wfp, "합 내림차순 정렬 후\n 이름  점수1  점수2  점수3  합  평균\n");
	for(i = 0; i < 5; i++) {
		fprintf(wfp, "%5s %5d %5d %5d %5d %7.2lf\n", s[i].name, s[i].s1, s[i].s2, s[i].s3, s[i].sum, s[i].result);
		// 7.out 파일에 이름과 총합, 평균을 합이 높은 순서로 정렬
	}

	printf("\n합 내림차순 정렬 후\n\t 이름 점수1 점수2 점수3    합    평균\n");
	for(i = 0; i < 5; i++) {
		printf("\t%5s %5d %5d %5d %5d %7.2lf\n", s[i].name, s[i].s1, s[i].s2, s[i].s3, s[i].sum, s[i].result);
	}

	fprintf(wfp, "\n과목별 평균\n");
	fprintf(wfp, "과목1: %.2lf, 과목2: %.2lf, 과목3: %.2lf\n", result1, result2, result3);
	// 과목별 평균을 파일에 출력

	printf("\n과목별 평균\n");
	printf("과목1: %.2lf 과목2: %.2lf 과목3: %.2lf\n", result1, result2, result3);
	// 과목별 평균을 터미널에 출력

	fclose(rfp); // 7.dat 파일 닫기

	fclose(wfp); // 7.out 파일 닫기

	return 0;
}
