#include "feed.h"
#include "display.h"
#include "result.h"

#ifndef GOTOXY
#define GOTOXY
#include "gotoxy.h"
#endif

#include <conio.h>
#include <stdio.h>

int step=0;
int startTime = GetTickCount();

void main(){
	char data;
	snake s1;
	feed f1;
	int SnakeSpeed=45;

	int SnakeSpeedArray[]={100,100,95,80,75,60,50,40,30,20,10,5,1};
	int LimitTimeArray[] ={60000 ,60000 ,55000,50000,45000,40000,35000,30000,25000,20000,15000,10000,5000};
	int NTailArray[]     ={5  ,7  ,10,15,30,35,40,45,50,57,63,67,70};
	
	display();

	do{
        inform(s1,f1,startTime,LimitTimeArray[step],SnakeSpeedArray[step],NTailArray[step],step);
		//버전1 inform(s1,f1,startTime,10000000000000,SnakeSpeed,99,0);
		
		if(f1.eatten){
			f1.pos=f1.makeFeed(s1);
			f1.eatten=false;
		}

		f1.drawFeed();

		if(f1.isiteatten(s1)&&s1.ntail<99){
			s1.ntail++;
		}
		
		
		if(!s1.Crash()){
			PrintResult(LimitTimeArray[step],s1.ntail,SnakeSpeedArray[step],0);	//버전1
			break;
		}
		
		if(s1.ntail>=NTailArray[step]){
			PrintResult(LimitTimeArray[step],s1.ntail,SnakeSpeedArray[step],1);
			s1.head.X=38;
			s1.head.Y=11;
			s1.ntail=1;
			startTime = GetTickCount();
			s1.GoAheadCOORD(s1.ntail);
			if(step<12) step++;
			display();
		}
		
		

		data = getch();
		
		if(kbhit())
			continue;
		
		ungetch(data);
		s1.move(data);
		
		Sleep(SnakeSpeedArray[step]);
		
	}while(1);
}
