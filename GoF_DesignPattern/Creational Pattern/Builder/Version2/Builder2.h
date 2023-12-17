#pragma once
#include <vector>
#include "Builder2_Components.h"

class ClockBuilder_V2
{
public:
	virtual ClockBuilder_V2& BuildClock(float radius, std::string name) { return *this; }
	virtual ClockBuilder_V2& BuildNumbers(int start, int end) { return *this; }
	virtual ClockBuilder_V2& BuildHands() { return *this; }
};

class StandardClockBuilder_V2 : public ClockBuilder_V2
{
public:
	virtual ClockBuilder_V2& BuildClock(float radius, std::string name) override;
	virtual ClockBuilder_V2& BuildNumbers(int start, int end) override;
	virtual ClockBuilder_V2& BuildHands() override;

	Clock_V2* MakeNewClock();

private:
	float radius = 10.f;
	std::string name = "None";
	int start = 1, end = 12;
	ClockHand_V2* hour_hand = nullptr;
	ClockHand_V2* minute_hand = nullptr;
	ClockHand_V2* second_hand = nullptr;
};

//¸ñ¼ö
class ClockMaker_V2
{
public:
	Clock_V2* CreateStandardClock();
	Clock_V2* CreateNoHandClock();

	void ShowClocksInfo();

private:
	std::vector<Clock_V2*> clocks;
};