#pragma once
#include <functional>
#include <iostream>

__interface Command
{
	void Execute();
};

class CommandTest
{
public:
	void HelloWorld()
	{
		std::cout << "Hello World!" << std::endl;
	}
};

#define STD_FUNCTION

template<typename Receiver>
class SimpleCommand : public Command
{
	//How Difference with using, typedef, std::function
#ifdef STD_FUNCTION
	using Action = std::function<void(Receiver*)>;
#elif USING
	using Action = void (Receiver::*)();
#else TYPEDEF
	typedef void(Receiver::*Action)();
#endif

public:
	SimpleCommand(Receiver* receiver, Action action);

	virtual void Execute() override;

private:
	Action action;
	Receiver* receiver;
};

template<typename Receiver>
SimpleCommand<Receiver>::SimpleCommand(Receiver* receiver, Action action)
	: receiver(receiver), action(action)
{
}

template<typename Receiver>
inline void SimpleCommand<Receiver>::Execute()
{
#ifdef STD_FUNCTION
	action(receiver);
#else
	(receiver->*action)();
#endif
}