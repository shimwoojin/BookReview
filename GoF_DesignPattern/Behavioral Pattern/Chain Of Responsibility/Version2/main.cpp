#include "ChainOfResponsibility2.h"

int main()
{
	ActionMan action_man;
	
	FlyHelper fly_helper;
	JumpHelper jump_helper;
	SprintHelper sprint_helper;

	action_man.SetAction(&fly_helper);
	action_man.DoAction();

	action_man.SetAction(&jump_helper);
	action_man.DoAction();

	action_man.SetAction(&sprint_helper);
	action_man.DoAction();

	return 0;
}