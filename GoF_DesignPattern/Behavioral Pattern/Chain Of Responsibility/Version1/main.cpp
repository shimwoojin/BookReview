#include "ChainOfResponsibility1.h"

int main()
{
	ActionChain action_chain;
	ActionMan action_man(&action_chain);

	action_man.Fly();

	return 0;
}