#include "Observer1.h"

int main()
{
	Subject subject1("subject1");

	Observer observer1("observer1");
	Observer observer2("observer2");
	Observer observer3("observer3");
	Observer observer4("observer4");
	
	subject1.Attach(&observer1);
	subject1.Attach(&observer2);
	subject1.Attach(&observer3);
	subject1.Attach(&observer4);

	subject1.Notify();

	return 0;
}