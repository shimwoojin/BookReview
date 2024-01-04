#include "Interpreter1.h"

BooleanExp::~BooleanExp()
{
}

VariableExp::VariableExp(std::string expression)
{
	this->expression = expression;
}

bool VariableExp::Evaluate(Context<bool>& context)
{
	return context.Lookup(expression);
}

AndExp::AndExp(BooleanExp* exp1, BooleanExp* exp2)
{
	expression1 = exp1;
	expression2 = exp2;
}

bool AndExp::Evaluate(Context<bool>& context)
{
	return expression1->Evaluate(context) && expression2->Evaluate(context);
}

OrExp::OrExp(BooleanExp* exp1, BooleanExp* exp2)
{
	expression1 = exp1;
	expression2 = exp2;
}

bool OrExp::Evaluate(Context<bool>& context)
{
	return expression1->Evaluate(context) || expression2->Evaluate(context);
}
