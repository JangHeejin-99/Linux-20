#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "chatt.h"
#include "info.h"

void L_chat() {
	key_t key;

	int shmid;

	char *shmaddr;

	char *buf;
	key = ftok("shmfile", 1); // 키 생성 
	shmid = shmget(key, 1024, IPC_CREAT|0666); // 공유 메모리 생성 
	shmaddr = (char*)shmat(shmid, NULL, 0); // 공유 메모리 연결 
	buf = shmaddr + 1; // 공유메모리[0]은 상태를 나타내는 flag, [1]부터 내용
	shmaddr[0] = READ_S_FLAG; // s가 메시지를 보내는 경우 

	while(1) {
		if (shmaddr[0] == READ_S_FLAG) { // 사용자1이 공유 메모리에 작성하는 경우 
			printf("%s >> ", nick); // 자신의 아이디 출력 
			fgets(buf, 256, stdin); // 내용 입력 
			buf[strlen(buf)-1]='\0';
			if (strlen(buf) != 0) // 내용이 아무것도 없으면 다음 상태로 못넘어감 
				shmaddr[0] = PRINT_R_FLAG; // 사용자2가 공유 메모리에 있는 내용 출력 
		}
		if(shmaddr[0] == PRINT_S_FLAG) { // 사용자1이 공유 메모리에 있는 내용을 출력해야하는 경우 
			if (strlen(buf) != 0) { // 내용이 아무것도 없으면 다음 상태로 못넘어감 
				puts(buf); // 다른 사용자가 공유 메모리에 입력한 내용 출력 
				strcat(buf, "");
				shmaddr[0] = READ_S_FLAG; // 사용자1이 다시 공유 메모리에 작성 
			}
		}
		if (strcmp(buf, "q") == 0) { // q가 입력되면 종료 
			printf("접속이 종료됩니다.\n");
			break;
		}
	}
	shmdt(shmaddr);
	shmctl(shmid, IPC_RMID, NULL); // 공유 메모리 연결 해제 및 삭제 
}
