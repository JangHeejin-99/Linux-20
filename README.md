# Linux Project

## Lab 01 ~ 07
- (상명대학교) 유닉스 프로그래밍 강의 실습

## Project 1
#### 주제
- 현재 지역 시간대로 시간을 받아 알람으로 설정된 시간이 되면 내용을 출력하도록 하는 프로그램
#### 시스템설계도
![image](https://user-images.githubusercontent.com/60311404/113160348-626d6780-9278-11eb-8136-d8b16f5f8b35.png)
#### 사용된기술
- 파일 입출력을 이용해 알람 시간과 내용을 텍스트 파일에 저장
- localtime 을 이용해 현재 시간을 계속 입력받음
- Tm 구조체를 이용해 현재 시간을 가져오고 입력받은 시간과 비교해 알람 출력
#### 사용 매뉴얼
- 알람을 설정하려면 y, 아니면 n
- 시간과 분, 알람 내용 입력
- 시간이 되면 알람 출력


## Project 2
#### 주제
- 공유메모리와 GTK, Database(sqlite3)를 이용한 채팅 프로그램
#### 시스템 설계도
- 사용자가 회원가입 시 그 정보를 Database에 저장하고 로그인
- 로그인한 정보를 가지고 공유 메모리를 이용해 채팅 진행
![image](https://user-images.githubusercontent.com/60311404/113161092-06efa980-9279-11eb-9083-60072b5d25a6.png)
![image](https://user-images.githubusercontent.com/60311404/113161104-09520380-9279-11eb-8ed8-d83547996a2a.png)
#### 사용된 기술
- Sqlite3를 이용한 회원 가입 정보 저장 및 로그인 확인
- GTK Library를 이용한 회원가입, 로그인, 채팅 시작 버튼 UI 활성화
- 공유 메모리를 이용한 1:1 채팅 지원
#### 사용 매뉴얼
![image](https://user-images.githubusercontent.com/60311404/113161897-c6446000-9279-11eb-8fd8-19d23f001a00.png)
1. Join
- join button 클릭 -> ID , PW , Nickname 입력 -> 정보가 db에 있는 경우 회원가입 실패, 없는 경우 성공
<회원가입 실패>
![image](https://user-images.githubusercontent.com/60311404/113161968-d3614f00-9279-11eb-855e-371848b12df5.png)
<회원가입 성공>
![image](https://user-images.githubusercontent.com/60311404/113162025-deb47a80-9279-11eb-90b1-7e99a6bf580c.png)
2. Login
- login button 클릭 -> ID , PW 입력 -> 둘 중 하나라도 틀렸으면 로그인 실패, 일치하면 로그인 성공
<로그인 성공>
![image](https://user-images.githubusercontent.com/60311404/113162062-e6741f00-9279-11eb-9ddb-8ffc414ae66b.png)
<로그인 성공>
![image](https://user-images.githubusercontent.com/60311404/113162180-06a3de00-927a-11eb-82c3-041588bc8bbc.png)
3. Chat Start
- User1이 button 클릭 -> User2가 버튼 클릭 -> User1이 채팅 입력 시 User2 채팅 화면에 내용 출력 -> User2가 채팅 입력 -> 반복 -> User1이나 User2 중 q를 입력하면 채팅 종료
![image](https://user-images.githubusercontent.com/60311404/113162247-14f1fa00-927a-11eb-97b2-29567e8e8138.png)
4. Quit
- quit buuton 클릭 -> 프로그램 종료
![image](https://user-images.githubusercontent.com/60311404/113162266-18858100-927a-11eb-93a1-0ab1278175c5.png)
