#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

int main(void) {
	struct stat buf; // 파일의 상태 및 정보를 저장할 buf 구조체 
	stat("password.txt", &buf);
	// inode에 저장된 파일 정보 검색
	// "password.txt"는 검색할 파일의 경로, 검색한 정보를 buf에 저장합니다.
	printf("Link Count before link()= %d\n", (int)buf.st_nlink);	
	// link전 hardlink된 개수 출력 

	link("password.txt", "password.ln"); 
	// password.ln은 password.txt와 동일한 inode를 사용한다.link시 inode에 저장된 링크 개수가 증가한다.

	stat("password.txt", &buf); // password.txt를 검색해 정보를 buf에 저장합니다.
	printf("Link Count after link()= %d\n", (int)buf.st_nlink);	
	// link후 hardlink된 수 출력 

	stat("password.ln", &buf); // password.ln을 검색해 정보를 buf에 저장합니다.
	printf("Link Count of password.ln= %d\n", (int)buf.st_nlink);
	// password.ln의 링크 개수를 출력

	symlink("password.txt", "password.sln"); // 심볼릭 링크 생성
	// 심볼릭 링크는 링크를 연결하여 원본 파일을 직접 사용하는 것과 같은 효과를 내는 링크입니다.

	stat("password.txt", &buf); // password.txt를 검색해 정보를 buf에 저장합니다.
	printf("Link Count of password.txt= %d\n", (int)buf.st_nlink);
	// password.txt의 링크 개수를 출력합니다.

	stat("password.sln", &buf); // password.sln을 검색해 정보를 buf에 저장합니다.
	printf("Link Count of password.sln= %d\n", (int)buf.st_nlink);
	/* password.sln의 링크 개수를 출력합니다. 
	-> password.sln 자신의 링크 개수가 출력되는 것이 아니라 
	링크로 연결되어 있는 password.txt의 링크 개수가 출력됩니다. */

	lstat("password.sln", &buf); // 심볼릭 링크 자체의 파일 정보를 검색한다 
	printf("Link Count of password.sln itself= %d\n", (unsigned int)buf.st_nlink);
	// 원본 파일에 대한 링크 개수가 출력 (password.sln의 링크 개수 출력)
	return 0;
}
