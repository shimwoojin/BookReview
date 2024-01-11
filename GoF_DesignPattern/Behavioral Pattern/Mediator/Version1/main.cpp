#include "Mediator1.h"

int main()
{
	EASoccerMediator* ea_soccer_mediator = new EASoccerMediator;

	Player* player1 = new Player("Son", ea_soccer_mediator, Team::A);
	Player* player2 = new Player("Lee", ea_soccer_mediator, Team::A);

	Player* player3 = new Player("Park", ea_soccer_mediator, Team::B);
	Player* player4 = new Player("Hwang", ea_soccer_mediator, Team::B);

	ea_soccer_mediator->Register(player1);
	ea_soccer_mediator->Register(player2);
	ea_soccer_mediator->Register(player3);
	ea_soccer_mediator->Register(player4);

	ea_soccer_mediator->Foul(player3);
	ea_soccer_mediator->Foul(player2);
	ea_soccer_mediator->Foul(player3);

	Player* player5 = new Player("Ki", ea_soccer_mediator, Team::B);

	ea_soccer_mediator->ChangePlayer(player5, player4);

	return 0;
}