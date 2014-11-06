#include<stdio.h>
#include<windows.h>
#include "snake.h"
#include "gotoxy.h"

#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define SPACE 32



snake::snake(){
	head.X=38;
	head.Y=11;
	for(int i=1;i<100;i++)
		tail[i].X=1, tail[i].Y=25;
	ntail=1;
	tail[0]=head;
}

void snake::move(char kind){
	if(ntail>0){
		draw(head);
	}
	
	if(kind==UP && head.Y >2){	
		eras(tail[ntail]);
		GoAheadCOORD(ntail);	
		head.Y--;
	}
	if(kind==DOWN && head.Y <24){	
		eras(tail[ntail]);
		GoAheadCOORD(ntail);
		head.Y++;
	}
	if(kind==RIGHT && head.X <76){
		eras(tail[ntail]);
		GoAheadCOORD(ntail);
		head.X++;
	}
	if(kind==LEFT && head.X >2){
		eras(tail[ntail]);
		GoAheadCOORD(ntail);
		head.X--;
	}
	// cheat
	//if(kind==SPACE && ntail<99){
	//	ntail++;
	//}
	tail[0]=head;
	drawHead(head);
}

void snake::GoAheadCOORD(int ntail){
	for(int i=ntail;i>0;i--)
		tail[i] = tail[i-1];
	tail[0]=head;
}

BOOL snake::Crash(){
	if(head.Y <=2 || head.Y >=24 || head.X >=76 || head.X <=2)
		return false;
	for(int i=1;i<=ntail;i++){
		if(tail[i].X==head.X && tail[i].Y==head.Y)
			return false;
	}
	return true;
}
void snake::DrawSnake(){
	drawHead(head);
	for(int i=0;i<=ntail;i++) draw(tail[i]);
}

void snake::ErasSnake(){
	eras(head);
	for(int i=0;i<=ntail;i++) eras(tail[i]);
}
void snake::draw(COORD pos){
	gotoxy(pos.X,pos.Y);
	printf("A");
}
void snake::drawHead(COORD pos){
	gotoxy(pos.X,pos.Y);
	printf("@");
}
void snake::eras(COORD pos){
	gotoxy(pos.X,pos.Y);
	printf(" ");
}