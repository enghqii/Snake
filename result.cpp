#include<stdio.h>
#include"gotoxy.h"
#include<windows.h>

bool PrintResult(int leftTime,int nTail,int speed,bool GoToNextStep){
	system("cls");
	
	gotoxy(25,15);
	printf("-���-");
	gotoxy(25,16);
	printf("���� �� : %d",nTail);
	gotoxy(25,17);
	printf("�� ���� �ð� : %d",leftTime);
	gotoxy(25,18);
	printf("�� �ӵ� : %d",speed);
	gotoxy(25,19);
	printf("go to next step : %s",GoToNextStep?" true":" false");
	gotoxy(25,20);
	system("pause");
	
	return GoToNextStep;
}