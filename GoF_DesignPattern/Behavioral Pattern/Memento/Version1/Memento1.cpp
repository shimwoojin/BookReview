#include "Memento1.h"
#include <iostream>

void MoveMemento::AddMovePoint(POINT point)
{
	move_points.push_back(point);
	
	if (move_points.size() >= limit)
	{
		move_points.pop_front();
	}
}

POINT MoveMemento::GetCurrentMovePoint(bool bRemove)
{
	POINT point = move_points.back();

	if (bRemove)
	{
		move_points.pop_back();
	}

	return point;
}

bool MoveMemento::IsExistMovePoint()
{
	return move_points.size() > 0;
}

Player::Player()
{
	CreateMoveMemento();
	location = { 0,0 };
}

Player::~Player()
{
	delete move_memento;
}

void Player::Move(int x, int y)
{
	location.x += x;
	location.y += y;

	move_memento->AddMovePoint(location);
}

void Player::Move_Undo()
{
	if (move_memento->IsExistMovePoint())
	{
		location = move_memento->GetCurrentMovePoint(true);
	}
}

void Player::ShowLocation()
{
	std::cout << "Player의 현재 위치 X : " << location.x << ", Y : " << location.y << "입니다. " << std::endl;
}

void Player::CreateMoveMemento()
{
	move_memento = new MoveMemento;
}
