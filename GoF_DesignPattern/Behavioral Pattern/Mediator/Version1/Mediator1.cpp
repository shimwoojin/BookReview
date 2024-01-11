#include "Mediator1.h"
#include <iostream>

void Player::Register()
{
	bOnPlaying = true;
	std::cout << name << " ������ ����忡 �����մϴ� ! " << std::endl;
}

void Player::UnRegister()
{
	bOnPlaying = false;
	std::cout << name << " ������ ����忡�� �����մϴ� ! " << std::endl;
}

void Player::Foul()
{
	++foul_count;
	
	if (foul_count >= 2)
	{
		soccer_mediator->UnRegister(this);

		std::cout << name << " ������ ���� ���߽��ϴ� ! " << std::endl;
	}
	else
	{
		std::cout << name << " ������ ���� ī�带 �޾ҽ��ϴ� ! " << std::endl;
	}
}

void EASoccerMediator::Foul(Player* player)
{
	player->Foul();
}

void EASoccerMediator::ChangePlayer(Player* in_player, Player* out_player)
{
	if (out_player->GetTeam() == Team::A)
	{
		if (TeamA.find(out_player) != TeamA.end())
		{
			Register(in_player);
			UnRegister(out_player);
		}
	}
	else if (out_player->GetTeam() == Team::B)
	{
		if (TeamB.find(out_player) != TeamB.end())
		{
			Register(in_player);
			UnRegister(out_player);
		}
	}
}

void EASoccerMediator::Register(Player* player)
{
	if (player->GetTeam() == Team::A)
	{
		TeamA.insert(player);
		player->Register();
	}
	else if (player->GetTeam() == Team::B)
	{
		TeamB.insert(player);
		player->Register();
	}
}

void EASoccerMediator::UnRegister(Player* player)
{
	if (player->GetTeam() == Team::A)
	{
		TeamA.erase(player);
		player->UnRegister();
	}
	else if (player->GetTeam() == Team::B)
	{
		TeamB.erase(player);
		player->UnRegister();
	}
}
