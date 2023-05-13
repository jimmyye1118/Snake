#ifndef Food_H
#define Food_H
#include <windows.h>
#include<cstdlib>
#define WIDTH 50
#define HEIGHT 25
class Food
{
private:
	COORD pos;
public:
	void gen_food();
	COORD get_pose();


};

#endif

