#include <sys/types.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(void) {
	int fd, pagesize, length;
	pid_t pid;
	caddr_t addr;
	
	pagesize = sysconf(_SC_PAGESIZE); // 메모리의 페이지 크기 정보 검색 
	length = 1*pagesize;

	if ((fd = open("test2.txt", O_RDWR | O_CREAT | O_TRUNC, 0666)) == -1) {
	/* test2.txt 오픈, 읽기 쓰기용, 파일이 없으면 생성, 
	이미 파일이 있고 쓰기 옵션이면 파일을 모두 지우고 길이 0으로 변경 */
		perror("open");
		exit(1);
	}


	if (ftruncate(fd, (off_t) length) == -1) {
	// ftruncate: 파일 기술자를 사용한 파일 크기 확장(일반 파일과 공유 메모리에만 사용 가능)
		perror("ftruncate");
		exit(1);
	}

	addr = mmap(NULL, length, PROT_READ|PROT_WRITE, MAP_SHARED, fd, (off_t)0);
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
			sleep(1);
			strcpy(addr, "Child Writes String\n"); // 매핑한 메모리에 데이터 쓰기 
			break;
		default: // parent process
			sleep(2);
			for(int i = 0; i < (int)strlen(addr); i++) {
				if (addr[i] >= 'a' && addr[i] <= 'z') // 소문자이면 
					addr[i]-=32; // 대문자로 변환 
				else if (addr[i] >= 'A' && addr[i] <= 'Z') // 대문자면 
					addr[i]+=32; // 소문자로 변환
			}
			printf("%s", addr);
			break;
	}

	return 0;
}
