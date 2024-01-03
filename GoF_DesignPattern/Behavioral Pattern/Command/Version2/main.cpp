#include "Command2.h"

int main()
{
	CommandTest command_test;
	SimpleCommand<CommandTest> simple_command(&command_test, &CommandTest::HelloWorld);

	simple_command.Execute();

	return 0;
}