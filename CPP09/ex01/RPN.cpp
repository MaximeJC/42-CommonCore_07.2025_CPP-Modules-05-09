#include "RPN.hpp"

RPN::RPN(const std::string& expression) : _expression(expression) {}

RPN::~RPN() {}

void RPN::execute() {
	try {
		checkExpression();
		for (size_t i = 0; i < _expression.length(); i++) {
			if (i % 2 == 1)
				continue;
			if (std::isdigit(_expression[i])) {
				_stack.push(_expression[i] - '0');
			} else {
				if (_stack.size() < 2)
					throw "Invalid expression (not enough numbers to do an operation)";
				int right = _stack.top();
				_stack.pop();
				int left = _stack.top();
				_stack.pop();
				_stack.push(calculate(left, right, _expression[i]));
			}
		}
		if (_stack.size() != 1)
			throw "Invalid expression (missing operators)";
		std::cout << _stack.top() << std::endl;
	} catch (const char* e) {
		std::cerr << "Error: " << e << std::endl;
	}
}

void RPN::checkExpression() {
	if (_expression.empty())
		throw "Empty expression";
	for (size_t i = 0; i < _expression.length(); i++) {
		if ((i % 2 == 0 && VAR_SET.find(_expression[i]) == std::string::npos)
			|| (i % 2 == 1 && _expression[i] != ' '))
			throw "Invalid expression";
	}
}

int RPN::calculate(int left, int right, char ope) {
	if (ope == '+') {
		long result = static_cast<long>(left) + static_cast<long>(right);
		if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
			throw "Integer overflow detected";
		return static_cast<int>(result);
	}
	if (ope == '-') {
		long result = static_cast<long>(left) - static_cast<long>(right);
		if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
			throw "Integer overflow detected";
		return static_cast<int>(result);
	}
	if (ope == '*') {
		long result = static_cast<long>(left) * static_cast<long>(right);
		if (result > std::numeric_limits<int>::max() || result < std::numeric_limits<int>::min())
			throw "Integer overflow detected";
		return static_cast<int>(result);
	}
	if (ope == '/' && right == 0)
		throw "Division by zero detected";
	if (ope == '/')
		return left / right;
	throw "Can't execute operation";
}
