#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	int pd, n;
	char inmsg[80];

	if ((pd = open("./TESTFIFO", O_RDONLY)) == -1) { // 서버측에서 생성한 FIFO 파일 열기 
	// 클라이언트 프로그램은 이미 testfifo파일이 있다고 가정하고 파일을 열고 있으므로 서버 프로그램을 먼저 실행해야합니다.
		perror("open");
		exit(1);
	}

	printf("Client =====\n");
	write(1, "From Server :", 13); // stdout(1): 표준 출력 

	while((n=read(pd, inmsg, 80)) > 0) // 서버가 보낸 데이터 읽기 
		write(1, inmsg, n); // 서버가 보낸 데이터 출력 

	if (n == -1) {
		perror("read");
		exit(1);
	}

	write(1, "\n", 1);
	close(pd);


	return 0;
}
