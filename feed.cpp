#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "snake.h"
#include "feed.h"
#include "gotoxy.h"


void feed::drawFeed(){
		gotoxy(pos.X,pos.Y);
		printf("F");
	}
bool feed::isiteatten(snake sn){
		if(sn.head.X==pos.X && sn.head.Y==pos.Y){
			eatten=TRUE;
			return true;
		}
		else
			return false;
	}
COORD feed::makeFeed(snake sn){
	COORD feedPos;
	srand(time(NULL));
	
	
	for(int i=0;i<sn.ntail;i++){
		feedPos.X=rand()%70+3;
		feedPos.Y=rand()%20+3;
		if(feedPos.X==sn.tail[i].X && feedPos.Y==sn.tail[i].Y){
			i=0;
		continue;
		}
	}
	
	return feedPos;		
}
