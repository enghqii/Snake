#ifndef SNAKE
#define SNAKE
class snake{
public:
	COORD head;
	COORD tail[100];
	int ntail;
	
	snake();
	
	void move(char kind);
	
	void GoAheadCOORD(int ntail);
	
	BOOL Crash();
	void DrawSnake();
	
	void ErasSnake();
private:
	void draw(COORD pos);
	void drawHead(COORD pos);
	void eras(COORD pos);

};

#endif