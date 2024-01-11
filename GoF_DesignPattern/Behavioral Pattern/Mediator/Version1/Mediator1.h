#pragma once
#include <set>
#include <string>

class Player;

enum class Team
{
	A,
	B
};

__interface SoccerMediator
{
	void Foul(Player* player);
	void ChangePlayer(Player* in_player, Player* out_player);
	void Register(Player* player);
	void UnRegister(Player* player);
};

class EASoccerMediator : public SoccerMediator
{
public:
	virtual void Foul(Player* player) override;
	virtual void ChangePlayer(Player* in_player, Player* out_player) override;
	virtual void Register(Player* player) override;
	virtual void UnRegister(Player* player) override;

private:
	std::set<Player*> TeamA;
	std::set<Player*> TeamB;
};

class Player
{
public:
	Player(std::string name, SoccerMediator* soccer_mediator, Team team)
		: name(name), soccer_mediator(soccer_mediator), team(team)
	{}

	void Register();
	void UnRegister();
	void Foul();
	Team GetTeam() { return team; }

private:
	std::string name;
	SoccerMediator* soccer_mediator;
	bool bOnPlaying = false;
	Team team;
	size_t foul_count = 0;
};