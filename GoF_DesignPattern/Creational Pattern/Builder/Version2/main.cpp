#include "Builder2.h"

int main()
{
	ClockMaker_V2 clock_maker_v2;

	clock_maker_v2.CreateStandardClock();
	clock_maker_v2.CreateNoHandClock();

	clock_maker_v2.ShowClocksInfo();

	return 0;
}