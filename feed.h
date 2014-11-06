#include<windows.h>
#include "snake.h"

#ifndef FEED
#define FEED
class feed{
public:
	COORD pos;
	bool eatten;
	
	feed(){
		eatten=true;
	}

	void drawFeed();
	bool isiteatten(snake sn);
	COORD makeFeed(snake sn);
};

#endif