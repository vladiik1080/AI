#include <iostream>
#include <vector>
#include <random>
#include <time.h>

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
			move = "UP";
			return move;
		}
		else if (x_move == 1)
		{
			move = "LEFT";
			return move;
		}
		else if (x_move == 2)
		{
			move = "RIGHT";
			return move;
		}
		else if (x_move == 3)
		{
			move = "DOWN";
			return move;
		}
		else if (x_move == 4)
		{
			move = "STAND";
			return move;
		}
	}

	string Get_info_object_Alive()
	{
		string alive;
		if (x_alive == 0)
		{
			alive = "EAT";
			return alive;
		}
		else if (x_alive == 1)
		{
			alive = "DEAD";
			return alive;
		}
		else if (x_alive == 2)
		{
			alive = "START";
			return alive;
		}
	}

private:
	Move x_move;
	Alive x_alive;
	Color x_color;
};

void Next_step()
{

}

void Show_table(vector <Object> table)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cout << table[i, j].Get_info_object_Alive()<<" ";
		}
		cout << endl;
	}
}

int main()
{
	vector <Object> table;
	for (int i = 0; i < 100; i++)
	{
		Object object;
		object.Object_init();
		table.push_back(object);
	}
	Show_table(table);

	return EXIT_SUCCESS;
}