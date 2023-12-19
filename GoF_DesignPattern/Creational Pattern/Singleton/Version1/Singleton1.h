#pragma once
#include <iostream>

template<typename T>
class Singleton
{
public:
	static T* Get()
	{
		if (instance == nullptr)
		{
			instance = new T;
		}
		return instance;
	}

	static void Delete()
	{
		delete instance;
		instance = nullptr;
	}

protected:
	Singleton() {}

private:
	static T* instance;
};

template<typename T>
T* Singleton<T>::instance = nullptr;

class AudioSystem : public Singleton<AudioSystem>
{
	friend class Singleton<AudioSystem>;

private:
	AudioSystem() {}

public:
	void Print() { std::cout << "temp : " << temp << std::endl; }

private:
	int temp = 10;
};