#include "Facade1.h"
#include <iostream>

void GoodNightMaker::HaveAGoodNight(Man* man, int sleep_horus, Bed::Type bed_type)
{
	GirlFriend girl_friend;
	Sleep sleep;
	Bed bed(bed_type);

	girl_friend.GoodNightKiss(man);

	if (sleep.EnsureGoodNight(man, sleep_horus) == false)
	{
		std::cout << "충분한 잠을 자지 못했습니다." << std::endl;
	}

	if (bed.IsSoftBed())
	{
		man->AddHappiness(20.0f);
	}
}

bool Sleep::EnsureGoodNight(Man* man, int hours)
{
	if (hours >= 8)
	{
		man->AddHappiness(hours * 5.0f);
		return true;
	}
	else
	{
		return false;
	}
}

void GirlFriend::GoodNightKiss(Man* man)
{
	man->AddHappiness(30.0f);
}
