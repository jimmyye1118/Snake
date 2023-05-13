#include<iostream>
#include <conio.h>
#include "Food.h"
#include "Snake.h"
#include <ctime>
#define WIDTH 50
#define HEIGHT 25
using namespace std;

Snake snake({ WIDTH / 2,HEIGHT / 2 },1);
Food food;
int score ;
const int interval = 100;

void board() {
	COORD snake_pos = snake.get_pos();
	COORD food_pos = food.get_pose();

	vector<COORD> snake_body = snake.get_body();
	cout << "Score: " << score << "\n\n";
	for (int i = 0; i < HEIGHT; i++) {
		cout << "\t\t#";
		for (int j = 0; j < WIDTH - 2; j++) {
			if (i == 0 || i == HEIGHT - 1) {
				cout << '#';
			}
			else if (i == snake_pos.Y && j+1 == snake_pos.X) {
				cout << '0';
			}
			else if (i == food_pos.Y && j+1 == food_pos.X) {
				cout << "*";
			}
			else {
				bool isBodyPart = false;
				for (int k = 0; k < snake_body.size()-1; k++) {
					if (i == snake_body[k].Y && j + 1 == snake_body[k].X) {
						cout << 'o';
						isBodyPart = true;
						break;
					}
				}
				if (!isBodyPart) cout << ' ';
			}
		}
		cout << "#\n";
	}
}

int main() {
	score = 0;
	srand(time(NULL));
	food.gen_food();

	bool game_over = false;
	while (!game_over) {
		board();
		if (_kbhit()) {
			switch (_getch()) {
			case 72:
				snake.Change_dir('u');break;
			case 75:
				snake.Change_dir('l');break;
			case 80:
				snake.Change_dir('d');break;
			case 77:
				snake.Change_dir('r');break;
			}
		}
		if (snake.collieded()) game_over = true;
		if (snake.eaten(food.get_pose())) {
			food.gen_food();
			snake.grow();
			score = score + 1;
		}
		snake.move_snake();
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 0,0 });
		Sleep(interval);
	}
	return 0;
}