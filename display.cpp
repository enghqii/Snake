#include <stdio.h>
#include "feed.h"
#include "gotoxy.h"
#include "result.h"
#include <windows.h>



void display(){
	system("cls");
	for(int i=1;i<76;i++){
		gotoxy(i,1);
		printf("%d",i%10);
		gotoxy(i,2);
		printf("-");
		gotoxy(i,24);
		printf("-");
	}
	for(int i=0;i<25;i++){
		gotoxy(1,i);
		printf("%d",i%10);
		gotoxy(2,i);
		printf("|");
		gotoxy(76,i);
		printf("|");
	}
}

/*시간이 다되었으면 0 , 아니면 남은시간 반환*/
int timeLimit(int startTime,int limitTime){
	if((GetTickCount()-startTime) <= limitTime)
		return limitTime - (GetTickCount()-startTime);
	else
		return false;
}

void inform(snake s1,feed f1,int startTime,int limitTime,int SnakeSpeed,int Tail_difficulty,int step){
	gotoxy(1,25);
	printf("                                                                        ");
	gotoxy(1,25);
	printf("뱀 속도 : %d  꼬리수:%d 목표 꼬리수:%d 스텝:%d ",SnakeSpeed,s1.ntail,Tail_difficulty,step);
	printf("먹이좌표: %d %d",f1.pos.X,f1.pos.Y);

	if(timeLimit(startTime,limitTime)){
		gotoxy(62,25);
		printf("남은시간:%d",timeLimit(startTime,limitTime));
	}
	else{
		if(PrintResult(limitTime,s1.ntail,SnakeSpeed,s1.ntail<Tail_difficulty?FALSE:TRUE)){
			s1.head.X=38;
			s1.head.Y=11;
			s1.ntail=1;
			extern int step;
			step++;
			extern int startTime;
			startTime=GetTickCount();
			s1.GoAheadCOORD(s1.ntail);
			display();
		}
		else return;
	}
}
