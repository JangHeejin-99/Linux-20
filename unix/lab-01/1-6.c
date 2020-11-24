#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	char *str;

	str = malloc(sizeof(char) * 20);
	// 인자로 지정한 크기의 메모리 할당 
	strcpy(str, "Hello");
	printf("%s\n", str);

	strcpy(str, "Good morning");
	printf("%s\n", str);

	free(str);
	// 메모리 해제
	return 0;
}
