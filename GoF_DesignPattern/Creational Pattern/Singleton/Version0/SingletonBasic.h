#pragma once

class Singleton
{
public:
	static Singleton* Instance()
	{
		if (instance == nullptr)
		{
			instance = new Singleton();
		}
		return instance;
	}

protected:
	Singleton() {}

private:
	static Singleton* instance;
};