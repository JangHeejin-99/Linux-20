#include "info.h"

int create_table(sqlite3* db);

sqlite3* open_db() { // database 파일 open 
	sqlite3* db = NULL;
	if (sqlite3_open("login.db", &db) != SQLITE_OK) { // login.db라는 database를 열어 연결해줍니다.
		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db)); // open에 실패했으면 오류 메시지 
		sqlite3_close(db);

		return NULL;
	}
	
	create_table(db);
	

	return db;
}

void close_db(sqlite3* db) { // db파일 닫기 
	if (db) {
		sqlite3_close(db);
		db = NULL;
	}
}

int create_table(sqlite3 *db) { // db 테이블 만들기 
	char *msg = 0;
	char *query = "CREATE TABLE LOGIN_INFO (ID TEXT PRIMARY KEY, PASSWORD TEXT, NICK TEXT);";
	/* LOGIN_INFO라는 이름을 가진 테이블을 생성하고 ID, PASSWORD, NICK이 테이블 칼럼
	   ID, PASSWORD, NICK의 데이터 타입은 TEXT, 기본키는 ID */
	if (!db)
		return -1;

	if (sqlite3_exec(db, query, NULL, NULL, &msg) != SQLITE_OK) { // 테이블 생성 
		sqlite3_free(msg); 
		return -1;
		// 테이블을 만들 수 없으면(테이블이 이미 있는 경우) -1 리턴
	}

	return 0;
}

int add_db(sqlite3 *db, char *id, char *pw, char *nick) { //db에 추가 
	char *msg = 0;
	char query[128] = {0,};

	if (!db || !id || !pw || !nick)
		return -1;

	sprintf(query, "INSERT INTO LOGIN_INFO (ID,PASSWORD,NICK) VALUES('%s', '%s', '%s');", id, pw, nick);
	// LOGIN_INFO 테이블에 ID, PASSWORD, NICK 추가함 
	if (sqlite3_exec(db, query, NULL, NULL, &msg) != SQLITE_OK) { // DB에 추가 
		fprintf(stderr, "Can't insert: %s\n", msg); // 실패 시 오류메시지 
		sqlite3_free(msg);
		return -1;
	}
	return 0;
}

static int search_sb(void *data, int argc, char **argv, char **col) { // 데이터 구조체에 검색된 내용 저장 
	login *user = (login*)data;
	// argv[0]: id, argv[1]: pw, argv[2]: nick, col[0]: ID, col[1]: PASSWORD, col[2]: NICK
	if(user) {
		if (argc == 3 && strcmp(col[0], "ID") == 0 && argv[0] && strcmp(argv[0], user->id) == 0
			&&strcmp(col[1], "PASSWORD") == 0 && strcmp(col[2], "NICK") == 0) {
				user->found = 1; // 검색되었으면 found=1
				if (argv[1]) 
					strcpy(user->pw, argv[1]); // user의 pw에 검색된 pw를 복사 
				if (argv[2])
					strcpy(user->nick , argv[2]); // user의 nick에 검색된 nick를 복사 
		}
	}
	return 0;
}

int search_db(sqlite3* db, char *id, char *pw) { // SELECT QUERY를 사용해 db검색 
	char *msg = 0;
	login user = {0,};
	char query[128] = {0,};

	if (!db || !id)
		return -1;

	memset(&user, 0, sizeof(login)); // user가 가리키는 메모리를 login의 크기 byte만큼 0으로 설정 

	sprintf(user.id, "%s", id); // user.id에 id 저장 
	sprintf(query, "SELECT * FROM LOGIN_INFO WHERE ID = '%s';", id); // primary key인 id를 이용해 검색 
	
	if (sqlite3_exec(db, query, search_sb, (void*)&user, &msg) != SQLITE_OK) { // 검색 
		fprintf(stderr, "Select failed: %s\n", msg); // 실패 시 오류 메시지 
		sqlite3_free(msg);
		return -1;
	}
	
	if (user.found) { // 원하는 경우를 찾았으면 
		if (strcmp(pw, user.pw) == 0) { // password를 비교했을 때 같은 경우 
			strcpy(nick, user.nick); // 닉네임을 저장하고 리턴 
			return 0;
		}
	}
	return -1;
}
				
void DB_Join() { // db를 이용해 회원가입 
	sqlite3 *db = open_db(); // db 열기 

	printf("=========JOIN=========\n");

	if (cnt == MAX_SIZE) { // 회원 최대수를 넘어가면 회원가입 실패 
		printf("회원가입할 수 없습니다.\n");
		exit(0);
	}

	printf("id > ");
	scanf("%s", id);

	printf("password > ");
	scanf("%s", password);

	printf("nick > ");
	scanf("%s", nick);

	cnt++;

	if (add_db(db, id, password, nick) == 0 ) { // 사용자 추가 
		printf("=========회원가입 완료=========\n");
	}
	sqlite3_close(db);
}

void DB_Login() { // db를 이용해 login 
	sqlite3 *db = open_db(); // db 열기 

	printf("=========LOGIN=========\n");

	printf("id > ");
	scanf("%s", id);
	
	printf("password > ");
	scanf("%s", password);

	if (search_db(db, id, password) != 0) { // id나 password가 일치하지 않는경우 
		printf(">> 로그인 정보가 없습니다.\n");
	}
	else { // 일치하는 경우 
		printf("=========로그인 성공=========\n");
	}
	sqlite3_close(db);
}

