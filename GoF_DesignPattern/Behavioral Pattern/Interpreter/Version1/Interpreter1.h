#pragma once
#include <string>
#include <map>

class VariableExp;

template<typename T>
class Context
{
public:
	bool Lookup(std::string str);
	void Assign(VariableExp* variable_exp, T value);

private:
	std::map<std::string, T> expression_map;
};

class BooleanExp
{
public:
	virtual ~BooleanExp();

	virtual bool Evaluate(Context<bool>& context) = 0;
};

class VariableExp : public BooleanExp
{
public:
	VariableExp(std::string expression);

	virtual bool Evaluate(Context<bool>& context) override;
	std::string GetExpression() { return expression; }

private:
	std::string expression;
};

class AndExp : public BooleanExp
{
public:
	AndExp(BooleanExp* exp1, BooleanExp* exp2);

	virtual bool Evaluate(Context<bool>& context) override;

private:
	BooleanExp* expression1;
	BooleanExp* expression2;
};

class OrExp : public BooleanExp
{
public:
	OrExp(BooleanExp* exp1, BooleanExp* exp2);

	virtual bool Evaluate(Context<bool>& context) override;

private:
	BooleanExp* expression1;
	BooleanExp* expression2;
};

template<typename T>
inline bool Context<T>::Lookup(std::string str)
{
	return expression_map[str];
}

template<typename T>
inline void Context<T>::Assign(VariableExp* variable_exp, T value)
{
	std::string expression = variable_exp->GetExpression();
	expression_map[expression] = value;
}
