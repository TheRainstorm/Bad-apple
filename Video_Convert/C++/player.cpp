#include <iostream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <time.h>

#define TXTFILE_PATH "RWBY_RedRose_88_312.txt"
#define BUFFSIZE 313
#define HEIGHT 88
using namespace std;

inline double mymax(double x){
    if(x>=0)
        return x;
    else
        return 0;
}
void gotoxy(int x, int y) {
    COORD pos = {x,y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);// ��ȡ��׼����豸���
    SetConsoleCursorPosition(hOut, pos);//���������ֱ���ָ���ĸ����壬����λ��
}
//void play_audio(){
//    system("mpv --no-video videos/will_play/BadApple384_512.mp4");
//}
int main(){
//    thread t(play_audio);
//    t.detach();
//    while(1){
//        printf("hello");
//        Sleep(1000);
//    }

	fstream in(TXTFILE_PATH,ios::in);
	int FRAME_NUM;//��Ƶ��֡��
	int FPS;//��Ƶ֡��ÿ��
	in>>FRAME_NUM;
	in>>FPS;

	char buffer[BUFFSIZE];//���ÿһ���ַ�
    int i,j;
	for(i=0;i<FRAME_NUM;i++){
        clock_t start_time = clock();
        for(j=0;j<HEIGHT;j++){
            in.getline(buffer,BUFFSIZE,'\n');
            printf("%s\n",buffer);
        }
        gotoxy(0,0);
        clock_t end_time = clock();
        float delta=static_cast<float>(end_time - start_time)/CLOCKS_PER_SEC*1000;//ms
        //printf("%f",delta);
		Sleep(mymax(1.0/FPS*1000- delta));
		//Sleep(1.0/FPS*1000- delta);//44*117��ȷ������0
	}
	return 0;
}
