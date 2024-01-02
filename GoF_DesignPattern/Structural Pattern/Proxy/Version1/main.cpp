#include "Proxy1.h"

int main()
{
	ComputerProxy computer_proxy;
	Son son;
	Mom mom;

	computer_proxy.AddAccessible(&mom);
	//computer_proxy.AddAccessible(&son);	//error!!
	computer_proxy.TogglePower(&mom);
	computer_proxy.TogglePower(&son);

	return 0;
}