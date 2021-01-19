#include "chatt.h"
#include "info.h"
#include <gtk/gtk.h>

#define LABEL_WIDTH 230
#define LABEL_HEIGHT 250

void DB_Join();
void DB_Login();
void T_chat();

void join_clicked(GtkWidget *widget, gpointer data) { // join button click
	DB_Join();
}

void login_clicked(GtkWidget *widget, gpointer data) { // login button click
	DB_Login();
}

void chat_clicked(GtkWidget* widget, gpointer data) { // chat button click
	T_chat();
}

void quit_clicked(GtkWidget* widget, gpointer data) { // quit button click
	gtk_main_quit(); // 종료 
}

int main(int argc, char *argv[]) {
	GtkWidget* window1;

	GtkWidget* label;
	
	GtkWidget* vbox;

	GtkWidget* join;
	GtkWidget* login;
	GtkWidget* chat;
	GtkWidget* quit;
	
	gtk_init(&argc, &argv); // 사용할 라이브러리를 초기화하고 디폴트로 signal handler 셋업 

	window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL); // window 생성

	g_signal_connect (G_OBJECT (window1), "destroy", G_CALLBACK (gtk_main_quit), NULL);
	// x버튼 클릭시 응용프로그램 종료 
	gtk_window_set_title (GTK_WINDOW(window1), "Chatting"); // window창 이름: chatting
	gtk_window_set_default_size (GTK_WINDOW(window1), LABEL_WIDTH, LABEL_HEIGHT); // window size 설정 
	gtk_window_set_position (GTK_WINDOW(window1), GTK_WIN_POS_CENTER); 
	// window 위치 (GTK_WIN_POS_CENTER = 센터)
	gtk_container_set_border_width (GTK_CONTAINER(window1), 15);
	vbox = gtk_vbox_new(TRUE, 1); // gtkvbox 생성 

	gtk_container_add(GTK_CONTAINER(window1), vbox);
	// window에 container vbox 추가 
	join = gtk_button_new_with_label("Join");
	login = gtk_button_new_with_label("Login");
	chat = gtk_button_new_with_label("Chat Start");
	quit = gtk_button_new_with_label("Quit");
	// button이름 설정 
	gtk_box_pack_start(GTK_BOX(vbox), join, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), login, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), chat, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(vbox), quit, TRUE, TRUE, 0);
	/* join, login, chat, quit box를 컨테이너(vbox)에 적재 */
	g_signal_connect (G_OBJECT(join), "clicked", G_CALLBACK(join_clicked), NULL);
	g_signal_connect (G_OBJECT(login), "clicked", G_CALLBACK(login_clicked), NULL);
	g_signal_connect (G_OBJECT(chat), "clicked", G_CALLBACK(chat_clicked), NULL);
	g_signal_connect (G_OBJECT(quit), "clicked", G_CALLBACK(quit_clicked), NULL); 
	/* click signal을 보내 click되면 join/login/chat/quit 함수가 실행되도록 함 */
	gtk_widget_show_all (window1); // widget show

	gtk_main();

	return 0;

}
