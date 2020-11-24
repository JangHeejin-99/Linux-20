#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main(void) {
	struct stat buf; // 파일의 상태 및 정보를 저장할 buf 구조체 
	stat("password.txt", &buf);
	// inode에 저장된 파일 정보 검색
	// "password.txt"는 검색할 파일의 경로, 검색한 정보를 buf에 저장합니다.

	printf("Inode = %d\n", (int)buf.st_ino); //inode number 출력
	printf("Mode = %o\n", (unsigned int)buf.st_mode); // 파일의 종류 및 접근 권한 출력
	printf("Nlink = %o\n", (unsigned int)buf.st_nlink); // hardlink 된 횟수 출력
	printf("UID = %d\n", (int)buf.st_uid); // (파일의 owner) user id 정보 출력 
	printf("GID = %d\n", (int)buf.st_gid); // group id of owner 정보 출력 
	printf("SIZE = %d\n", (int)buf.st_size); // 파일의 크기(bytes) 출력 
	printf("Atime = %d\n", (int)buf.st_atime); // 가장 최근 접근 시간 출력
	printf("Mtime = %d\n", (int)buf.st_mtime); // 최근에 파일이 변경된 시간 출력 
	printf("Ctime = %d\n", (int)buf.st_ctime); // 최근 상태가 변화된 시간 출력 
	printf("Blksize = %d\n", (int)buf.st_blksize); // 파일 시스템의 block 크기 
	printf("Blocks = %d\n", (int)buf.st_blocks); // 할당된 512B blocks의 수 출력

	return 0;
}
