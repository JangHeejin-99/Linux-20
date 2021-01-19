#include <sqlite3.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 256
typedef struct Login {
	char id[32];
	char pw[32];
	char nick[32];
	int found;
}login;

int cnt;
char id[32];
char password[32];
char nick[32];
