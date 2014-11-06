#include<stdio.h>
#include"gotoxy.h"
#include<windows.h>

bool PrintResult(int leftTime,int nTail,int speed,bool GoToNextStep){
	system("cls");
	
	gotoxy(25,15);
	printf("-°á°ú-");
	gotoxy(25,16);
	printf("²¿¸® ¼ö : %d",nTail);
	gotoxy(25,17);
	printf("ÃÑ Á¦ÇÑ ½Ã°£ : %d",leftTime);
	gotoxy(25,18);
	printf("¹ì ¼Óµµ : %d",speed);
	gotoxy(25,19);
	printf("go to next step : %s",GoToNextStep?" true":" false");
	gotoxy(25,20);
	system("pause");
	
	return GoToNextStep;
}