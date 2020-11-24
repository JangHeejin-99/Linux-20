#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
	char name[10]; // 학생 이름
	int k1; // 국어 점수
	int e1; // 영어 점수
	int m1; // 수학 점수
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
	char a[10];
	int n;
	int k_sum=0, e_sum=0, m_sum=0; // 국어, 영어, 수학 총 합
	double k_result=0, e_result=0, m_result=0; // 국어, 영어, 수학 평균
	int i = 0;

	if ((rfp = fopen("3-8.dat", "r")) == NULL) { // 3-8.dat을 읽기 모드로 open
		perror("fopen: 3-8.dat"); // 에러 메시지 출력
		exit(1);
	}

	if ((wfp = fopen("3-8.out", "w")) == NULL) { // 3-8.out를 쓰기 모드로 open
		perror("fopen: 3-8.out"); // 에러 메시지 출력
		exit(1);
	}

	fscanf(rfp, "%*s %*s %*s"); // [%*]을 사용하면 값을 읽지 않음
 
	while((n = fscanf(rfp, "%s %d %d %d", s[i].name, &s[i].k1, &s[i].e1, &s[i].m1)) != EOF) {
	// 이름과 국어 점수, 영어 점수, 수학 점수를 3-8.dat에서 읽어들임 (파일의 끝까지)
		s[i].sum = s[i].k1 + s[i].e1 + s[i].m1; // 각 학생의 합
		s[i].result = s[i].sum / 3; // 각 학생의 평균
		k_sum += s[i].k1; e_sum += s[i].e1; m_sum += s[i].m1; // 국어, 영어, 수학별 총합
		k_result=k_sum/3; e_result=e_sum/3; m_result=m_sum/3; // 국어, 영어, 수학별 평균
		i++;
	}
	qsort(s, 5, sizeof(s[0]), compare); //qsort 함수(정렬할 배열, 정렬할 원소 개수, 원소 하나의 크기, 비교 알고리즘)

	fseek(rfp, 0, SEEK_SET); // 3-8.dat의 오프셋 위치를 처음으로 되돌림

	fprintf(wfp, "================합이 높은 순서대로 출력================\n이름 합 평균\n");
	for(i = 0; i < 5; i++) {
		fprintf(wfp, "%s %d %.2lf\n", s[i].name, s[i].sum, s[i].result);
		// 3-8.out 파일에 이름과 총합, 평균을 합이 높은 순서로 정렬
	}

	fprintf(wfp, "================과목별 평균================\n");
	fprintf(wfp, "국어: %.2lf, 영어: %.2lf, 수학: %.2lf\n", k_result, e_result, m_result);
	// 과목별 평균을 파일에 출력

	printf("================과목별 평균================\n");
	printf("국어: %.2lf 영어: %.2lf 수학: %.2lf\n", k_result ,e_result, m_result);
	// 과목별 평균을 터미널에 출력

	fclose(rfp); // 3-8.dat 파일 닫기

	fclose(wfp); // 3-8.out 파일 닫기

	return 0;
}
