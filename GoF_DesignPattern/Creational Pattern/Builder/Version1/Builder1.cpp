#include "Builder1.h"

void StandardClockBuilder::BuildClock(float radius, std::string name)
{
	clock = new Clock;
	clock->SetBodyRadius(radius);
	clock->SetName(name);
}

void StandardClockBuilder::BuildNumbers(int start, int end)
{
	if (clock)
	{
		clock->AddNumbers(start, end);
	}
}

void StandardClockBuilder::BuildHands()
{
	if (clock)
	{
		ClockHand* hour_hand = new ClockHand;
		hour_hand->handtype = HandType::hour;
		clock->SetHourHand(hour_hand);

		ClockHand* minute_hand = new ClockHand;
		minute_hand->handtype = HandType::minute;
		clock->SetMinuteHand(minute_hand);

		ClockHand* second_hand = new ClockHand;
		second_hand->handtype = HandType::second;
		clock->SetSecondHand(second_hand);
	}
}

Clock* StandardClockBuilder::GetClock()
{
	return clock;
}

Clock* ClockMaker::CreateStandardClock()
{
	StandardClockBuilder clock_builder;
	
	clock_builder.BuildClock(10.f, "standard_clock");
	clock_builder.BuildNumbers(1, 12);
	clock_builder.BuildHands();

	clocks.push_back(clock_builder.GetClock());

	return clocks.back();
}

Clock* ClockMaker::CreateNoHandClock()
{
	StandardClockBuilder clock_builder;

	clock_builder.BuildClock(20.f, "no_hand_clock");
	clock_builder.BuildNumbers(1, 4);

	clocks.push_back(clock_builder.GetClock());

	return clocks.back();
}

void ClockMaker::ShowClocksInfo()
{
	for (auto& clock : clocks)
	{
		clock->ShowClockInfo();
	}
}
