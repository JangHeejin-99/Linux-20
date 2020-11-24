#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *fname;
	char fntmp[BUFSIZ];
	char template[32];

	fname = tmpnam(NULL);
	// tmpnam: 기존 파일과 이름이 같지 않은 유효한 파일명을 생성
	// tmpnam(NULL): tmpnam함수는 결과를 내부 정적 버퍼에 둡니다.
	printf("1. TMP File Name(tmpnam) : %s\n", fname); 

	tmpnam(fntmp);
	// tmpnam은 기존 파일과 이름이 같지 않은 유효한 파일명을 생성하고 fntmp에 저장됩니다.
	printf("2. TMP File Name(tmpnam) : %s\n", fntmp);

	fname = tempnam("/tmp", "coredump");
	// tempnam: 임의의 이름을 가진 파일을 반환하는 함수
	/* 첫번째 인자(/tmp)는 임시 파일이 만들어질 임시 디렉토리, 
	  두번째 인자(coredump)는 값이 NULL이 아닌 경우 작성되는 파일명의 최초의 부분입니다. */
	printf("3. TMP File Name(tempnam) : %s\n", fname);

	strcpy(template, "/tmp/coredumpXXXXXX");
	// template에 /tmp/coredumpXXXXXX 복사
	fname = mktemp(template);
	// mktemp: template 매개변수로 주어진 틀을 이용해 고유한 파일 이름 생성
	// template매개변수는 문자 X가 6개로 끝나야한다
	printf("4. TMP File Name(mktemp) : %s\n", fname);

	return 0;
}
