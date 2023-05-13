#ifndef Snake_H
#define  Snake_H
#define WIDTH 50
#define HEIGHT 25
#include <vector>
#include<iostream>
#include<windows.h>
using namespace std;

class Snake
{
private:
	COORD pos;
	int len;
	int vel;
	char direction;
	vector<COORD>body;
public:
	Snake(COORD pos, int vel);
	void Change_dir(char dir);
	vector<COORD> get_body();
	void move_snake();
	COORD get_pos(); //get curremt position
	bool eaten(COORD food_pos);
	void grow();
	bool collieded();
};
#endif
