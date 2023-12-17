#include "Builder2.h"

ClockBuilder_V2& StandardClockBuilder_V2::BuildClock(float radius, std::string name)
{
	this->radius = radius;
	this->name = name;

	return *this;
}

ClockBuilder_V2& StandardClockBuilder_V2::BuildNumbers(int start, int end)
{
	this->start = start;
	this->end = end;

	return *this;
}

ClockBuilder_V2& StandardClockBuilder_V2::BuildHands()
{
	ClockHand_V2* hour_hand = new ClockHand_V2;
	hour_hand->handtype = HandType::hour;
	this->hour_hand = hour_hand;

	ClockHand_V2* minute_hand = new ClockHand_V2;
	minute_hand->handtype = HandType::minute;
	this->minute_hand = minute_hand;

	ClockHand_V2* second_hand = new ClockHand_V2;
	second_hand->handtype = HandType::second;
	this->second_hand = second_hand;

	return *this;
}

Clock_V2* StandardClockBuilder_V2::MakeNewClock()
{
	Clock_V2* clock = new Clock_V2;

	clock->SetName(name);
	clock->SetBodyRadius(radius);
	clock->AddNumbers(start, end);
	clock->SetHourHand(hour_hand);
	clock->SetMinuteHand(minute_hand);
	clock->SetSecondHand(second_hand);

	return clock;
}

Clock_V2* ClockMaker_V2::CreateStandardClock()
{
	StandardClockBuilder_V2 clock_builder;
	
	clock_builder
	.BuildClock(10.f, "standard_clock")
	.BuildNumbers(1, 12)
	.BuildHands();

	clocks.push_back(clock_builder.MakeNewClock());

	return clocks.back();
}

Clock_V2* ClockMaker_V2::CreateNoHandClock()
{
	StandardClockBuilder_V2 clock_builder;

	clock_builder
	.BuildClock(20.f, "no_hand_clock")
	.BuildNumbers(1, 4);

	clocks.push_back(clock_builder.MakeNewClock());

	return clocks.back();
}

void ClockMaker_V2::ShowClocksInfo()
{
	for (auto& clock : clocks)
	{
		clock->ShowClockInfo();
	}
}
