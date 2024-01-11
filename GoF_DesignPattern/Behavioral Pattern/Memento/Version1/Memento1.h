#pragma once
#include <windows.h>
#include <deque>

class MoveMemento;

class Player
{
public:
	Player();
	~Player();

public:
	void Move(int x, int y);
	void Move_Undo();

	void ShowLocation();

private:
	void CreateMoveMemento();

private:
	MoveMemento* move_memento;
	POINT location;
};

class MoveMemento
{
	friend class Player;

private:
	void AddMovePoint(POINT point);
	POINT GetCurrentMovePoint(bool bRemove);
	bool IsExistMovePoint();

private:
	std::deque<POINT> move_points;
	size_t limit = 10;
};