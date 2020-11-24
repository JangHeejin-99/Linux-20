#include <pwd.h>
#include <stdio.h>

int main(void) {
	struct passwd *pw;
	// passwd 구조체 *pw
	pw = getpwnam("heejin"); // 이름으로 passwd 파일 읽기 
	printf("UID : %d\n", (int)pw->pw_uid); // user id 출력 
	printf("Name : %s\n", pw->pw_name); // name 출력 
	printf("Home Directory : %s\n", pw->pw_dir); // 홈 디렉토리 출력 
	printf("Default Shell : %s\n", pw->pw_shell); // shell 출력 

	return 0;
}
