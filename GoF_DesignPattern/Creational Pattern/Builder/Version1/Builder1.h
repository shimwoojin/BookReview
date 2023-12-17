#pragma once
#include <vector>
#include "Builder1_Components.h"

class ClockBuilder
{
public:
	virtual void BuildClock(float radius, std::string name) { }
	virtual void BuildNumbers(int start, int end) { }
	virtual void BuildHands() { }
};

class StandardClockBuilder : public ClockBuilder
{
public:
	virtual void BuildClock(float radius, std::string name) override;
	virtual void BuildNumbers(int start, int end) override;
	virtual void BuildHands() override;

	Clock* GetClock();

private:
	Clock* clock = nullptr;
};

//¸ñ¼ö
class ClockMaker
{
public:
	Clock* CreateStandardClock();
	Clock* CreateNoHandClock();

	void ShowClocksInfo();

private:
	std::vector<Clock*> clocks;
};