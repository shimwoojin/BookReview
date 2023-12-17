#include "Builder1.h"

int main()
{
	ClockMaker clock_maker;

	clock_maker.CreateStandardClock();
	clock_maker.CreateNoHandClock();

	clock_maker.ShowClocksInfo();

	return 0;
}