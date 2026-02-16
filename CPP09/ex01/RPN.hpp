#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <cctype>
#include <limits>

#define VAR_SET std::string("0123456789+-*/")

class RPN {
public:
    RPN(const std::string& expression);
	~RPN();

	void execute();
private:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);

    std::string _expression;
	std::stack<int> _stack;

	void checkExpression();
	int calculate(int left, int right, char ope);
};

#endif
