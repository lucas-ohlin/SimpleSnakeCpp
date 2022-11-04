#include <iostream>
#include <conio.h>

using namespace std;

//Global variables
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;

//Enum of player input
enum eDirection {

	STOP = 0,
	LEFT,
	RIGHT,
	UP,
	DOWN,

};

eDirection dir;

void Setup() {

	gameOver = false;
	dir = STOP;

	//Snake will spawn at center of map
	x = width / 2;
	y = height / 2;

	//Place fruit randomly on the map
	//From 0 to width - 1
	fruitX = rand() % width;
	fruitY = rand() % height;

	//Set the score
	score = 0;

}

void Draw() {

	//Clears the console
	system("cls");

	//Wall top of the map
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	for (int i = 0; i < height; i++) {

		for (int j = 0; j < width; j++) {

			//Walls
			if (j == 0)
				cout << "#";

			//Player
			if (i == y && j == x)
				cout << "o";

			//Fruit
			else if (i == fruitY && j == fruitX)
				cout << "X";

			//Empty space
			else
				cout << " ";

			//Walls
			if (j == width - 1)
				cout << "#";

		}

		cout << endl;
		 
	}

	//Wall bottom of the map
	for (int i = 0; i < width + 2; i++)
		cout << "#";
	cout << endl;

	//Print out score
	cout << "Score: " << score << endl;

}

void Input() {

	//If keyboard is pressed 1 if pressed 0 if not
	if (_kbhit()) {

		//Get the key that was pressed
		switch (_getch()) {

			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
			default:
				break;

		}

	}

}

void Logic() {

	switch (dir) {

		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;

	}

	//Check if player runs into a wall
	if (x > width || x < 0 || y > height || y < 0) {

		gameOver = true;

	}

	//Check if player is on fruit cords
	if (x == fruitX && y == fruitY) {

		score++;

		//Place fruit randomly on the map
		//From 0 to width - 1
		fruitX = rand() % width;
		fruitY = rand() % height;

	}

}

int main() {

	Setup();

	//While gameOver isnt true
	while (!gameOver) {

		//Will draw the playing screen
		Draw();

		//Player input
		Input();

		//General logic
		Logic();

	}

	return 0;

}
