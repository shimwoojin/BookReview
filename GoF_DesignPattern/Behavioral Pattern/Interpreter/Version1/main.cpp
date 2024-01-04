#include "Interpreter1.h"
#include <iostream>

int main()
{
	BooleanExp* expression1;
	BooleanExp* expression2;
	Context<bool> context;

	VariableExp* x = new VariableExp("X");
	VariableExp* y = new VariableExp("Y");

	context.Assign(x, true);
	context.Assign(y, false);

	expression1 = new OrExp(
		new AndExp(x, y),
		new AndExp(x, x)
	);

	expression2 = new OrExp(
		new AndExp(x, y),
		new AndExp(x, y)
	);

	bool result1 = expression1->Evaluate(context);
	bool result2 = expression2->Evaluate(context);

	std::cout << result1 << std::endl;
	std::cout << result2 << std::endl;

	return 0;
}