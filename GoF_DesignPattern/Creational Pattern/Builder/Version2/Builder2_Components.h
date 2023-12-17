#pragma once
#include <vector>
#include <iostream>

enum class HandType
{
	second,
	minute,
	hour
};

class ClockHand_V2
{
public:
	HandType handtype;
};

class Clock_V2
{
public:
	void ShowClockInfo()
	{
		using namespace std;

		cout << "clock_name : " << name << endl;

		cout << "body_radius : " << body_radius << endl;
		
		cout << "numbers : ";
		for (int num : numbers)
		{
			cout << num << " ";
		}
		cout << "\n";

		if (hour_hand)
		{
			cout << "hour_hand : " << (int)hour_hand->handtype << endl;
		}

		if (minute_hand)
		{
			cout << "minute_hand : " << (int)minute_hand->handtype << endl;
		}

		if (second_hand)
		{
			cout << "second_hand : " << (int)second_hand->handtype << endl;
		}

		cout << endl;
	}

public:
	void SetName(std::string name)
	{
		this->name = name;
	}

	void AddNumbers(int start, int end)
	{
		for (int i = start; i <= end; i++)
		{
			numbers.push_back(i);
		}
	}

	void SetHourHand(ClockHand_V2* hour_hand)
	{
		this->hour_hand = hour_hand;
	}

	void SetMinuteHand(ClockHand_V2* minute_hand)
	{
		this->minute_hand = minute_hand;
	}

	void SetSecondHand(ClockHand_V2* second_hand)
	{
		this->second_hand = second_hand;
	}

	void SetBodyRadius(float body_radius)
	{
		this->body_radius = body_radius;
	}

private:
	std::string name;

	std::vector<int> numbers;

	ClockHand_V2* hour_hand;
	ClockHand_V2* minute_hand;
	ClockHand_V2* second_hand;

	float body_radius;
};