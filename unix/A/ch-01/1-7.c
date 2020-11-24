#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	int n;
	extern char *optarg; // 옵션 인자 저장 
	extern int optind; // 다음에 처리할 argv의 주소 

	printf("Current optind: %d\n", optind);
	while((n = getopt(argc, argv, "abc:")) != -1) {
		switch(n) {
		case 'a':
			printf("Option: a\n");
			break;
		case 'b':
			printf("Option: b\n");
			break;
		case 'c':
			printf("Option: c, argument = %s\n", optarg);
			break;
		}
		printf("Next optind: %d\n", optind);
	}

	return 0;
}

