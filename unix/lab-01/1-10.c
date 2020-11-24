#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int sum(int argc, char *argv[]);
int multi(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	int n, ind = 0;;
	extern char *optarg; // 옵션 인자 저장 
	extern int optind; // 다음에 처리할 argv의 주소 

	while((n = getopt(argc, argv, "am:")) != -1) {
		ind = 1;
		switch(n) {
		case 'a':
			printf("%d\n", sum(argc, argv));
			break;
		case 'm':
			printf("%d\n", multi(argc, argv));
			break;
		default:
			printf("1-9: 부적절한 옵션 --'%s'", argv[0]);
			break;
		}
	}

	if(ind == 0)
		printf("%d\n",sum(argc, argv));
	return 0;
}

int sum(int argc, char *argv[]) {
	int sum = 0;
	for(int i = 0; i < argc; i++)
		sum += atoi(argv[i]);
	return sum;
}

int multi(int argc, char *argv[]) {
	int result = 1;
	for(int i = 2; i < argc; i++)
		result *= atoi(argv[i]);
	return result;
}

	
