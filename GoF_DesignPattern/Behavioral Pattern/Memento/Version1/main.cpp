#include "Memento1.h"

int main()
{
	Player* player = new Player;

	player->Move(1, 0);
	player->ShowLocation();
	player->Move(1, 0);
	player->ShowLocation();
	player->Move(1, 0);
	player->ShowLocation();
	player->Move(0, 1);
	player->ShowLocation();
	player->Move(0, 1);
	player->ShowLocation();
	player->Move(0, 1);
	player->ShowLocation();
	
	player->Move_Undo();
	player->ShowLocation();
	player->Move_Undo();
	player->ShowLocation();
	player->Move_Undo();
	player->ShowLocation();

	return 0;
}