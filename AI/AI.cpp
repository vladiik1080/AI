#include <iostream>
#include <vector>
#include <random>
#include <time.h>
#include "windows.h"

using namespace std;

enum Move {
	UP,
	LEFT,
	RIGHT,
	DOWN,
	STAND
};
enum Alive {
	EAT,
	DEAD,
	START
};

// WHITE - start, YELLOW - 1-st level, GREEN - 2-nd level, RED - dead.
enum Color {
	WHITE,
	YELLOW,
	GREEN,
	RED
};

struct Object
{
public:

	Object() {}

	Object(Alive alive, Color color, Move move)
		:x_alive(alive), x_color(color), x_move(move) {}

	void Object_init()
	{
		x_alive = START;
		x_color = WHITE;
		x_move = STAND;
	}

	string Get_info_object_Move()
	{
		string move;
		if (x_move == 0)
		{
			move = "\x1B[34mU\033[0m";
			return move;
		}
		else if (x_move == 1)
		{
			move = "\x1B[34mL\033[0m";
			return move;
		}
		else if (x_move == 2)
		{
			move = "\x1B[34mR\033[0m";
			return move;
		}
		else if (x_move == 3)
		{
			move = "\x1B[34mD\033[0m";
			return move;
		}
		else if (x_move == 4)
		{
			move = "S";
			return move;
		}
	}

	string Get_info_object_Alive()
	{
		string alive;
		if (x_alive == 0)
		{
			alive = "E";
			return alive;
		}
		else if (x_alive == 1)
		{
			alive = "D";
			return alive;
		}
		else if (x_alive == 2)
		{
			alive = "S";
			return alive;
		}
	}

	string Get_info_object_Color()
	{
		string color;
		if (x_color == 0)
		{
			color = "W";
			return color;
		}
		else if (x_color == 1)
		{
			color = "\x1B[33mY\033[0m";
			return color;
		}
		else if (x_color == 2)
		{
			color = "\x1B[32mG\033[0m";
			return color;
		}
		else if (x_color == 3)
		{
			color = "\x1B[31mR\033[0m";
			return color;
		}
	}

	void Set_color()
	{
		int s_color = rand() % 4;
		if (s_color == 0)
			x_color = WHITE;
		else if (s_color == 1)
			x_color = YELLOW;
		else if (s_color == 2)
			x_color = GREEN;
		else if (s_color == 3)
			x_color = RED;
	}

	void Set_move()
	{
		int s_move = rand() % 5;
		if (s_move == 0)
			x_move = UP;
		else if (s_move == 1)
			x_move = LEFT;
		else if (s_move == 2)
			x_move = RIGHT;
		else if (s_move == 3)
			x_move = DOWN;
		else if (s_move == 4)
			x_move = STAND;

	}

private:
	Move x_move;
	Alive x_alive;
	Color x_color;
};

void Show_table(vector <Object> table)
{
	int l = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << "Alive-" << table[l].Get_info_object_Alive() << "," << "Move-" << table[l].Get_info_object_Move() << ","<<"Color-"<< table[l].Get_info_object_Color()<<";";
			l++;
		}
		cout << endl;
	}
}

int main()
{
	srand(time(NULL));
	vector <Object> table;
	for (int i = 0; i < 25; i++)
	{
		Object object;
		object.Object_init();
		table.push_back(object);
	}
	Show_table(table);
	system("cls");
	for (int k = 0; k < 10; k++)
	{
		system("cls");
		for (int i = 0; i < 25; i++)
		{
			table[i].Set_color();
			table[i].Set_move();
		}
		Show_table(table);
		Sleep(2000);
	}
	//printf("\x1B[35mTexting\033[0m\n");	purple


	return EXIT_SUCCESS;
}