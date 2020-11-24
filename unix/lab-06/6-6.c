#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	int fd;
	pid_t pid;
	caddr_t addr;
	struct stat statbuf;

	if (argc != 2) { // 파일명 입력 X 
		fprintf(stderr, "Usage : %s filename\n", argv[0]);
		exit(1);
	}

	if (stat(argv[1], &statbuf) == -1) { // stat: 파일의 정보를 얻는 함수 
		perror("stat"); // 정보를 못가져왔을 시 에러메시지 출력 
		exit(1);
	}

	if ((fd = open(argv[1], O_RDWR)) == -1) { // O_RDWR(읽기, 쓰기권한 허용)
		perror("open"); // 파일 오픈 실패 시 에러메시지 출력 
		exit(1);
	}

	addr = mmap(NULL, statbuf.st_size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
	/* mmap(addr(매핑할 메모리 주소), len(메모리 공간의 크기), prot(보호모드),
	 flags(매핑된 데이터의 처리방법을 지정하는 상수), fildes(파일 기술자), off(파일 오프셋))
	-> fildes가 가리키는 파일에서 off로 지정한 오프셋부터 len크기만큼 데이터를 읽어 
	addr이 가리키는 메모리 공간에 매핑 -> 수행 성공 시 메모리의 시작 주소 리턴 */
	/* PROT_READ(매핑된 파일 읽기만), PROT_WRITE(매핑된 파일에 쓰기 허용)
	   MAP_SHARED: 다른 사용자와 데이터 변경 내용 공유, 쓰기 동작은 매핑된 메모리의 내용 변경 */
	if (addr == MAP_FAILED)	 { // 수행 실패 시 
		perror("mmap");
		exit(1);
	}
	close(fd);

	switch(pid = fork()) { // 자식 프로세스 생성 
		case -1: // fork failed
			perror("fork");
			exit(1);
			break;
		case 0: // child process
			printf("1. Child Process :addr=%s", addr);
			sleep(1); // 1초 쉼 
			addr[0] = 'C'; // 파일 내용 변경  
			printf("2. Child Process :addr=%s", addr);
			sleep(2);
			printf("3. Child Process :addr=%s", addr);
			break;
		default: // parent process
			printf("1. Parent Process :addr=%s", addr);
			sleep(2);
			printf("2. Parent Process :addr=%s", addr);
			addr[1] = 'P'; // 파일 내용 변경 
			printf("3. Parent Process :addr=%s", addr);
			sleep(2);
			break;
	}

	return 0;
}
