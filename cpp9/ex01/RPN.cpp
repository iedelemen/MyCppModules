#include "RPN.hpp"

RPN::RPN(string arg){
	if (arg.empty())
		throw std::runtime_error("Empty expression");
	if (arg.find_first_not_of("0123456789+-*/ ") != string::npos)
		throw std::runtime_error("Invalid expression");
	check(arg);

}

RPN::~RPN(){}

RPN::RPN(const RPN &other) {
	*this = other;
}

RPN &RPN::operator=(const RPN &other) {
	if (this != &other)
		_stack = other._stack;
	return *this;
}

void RPN::check(string arg){
	std::istringstream ss(arg);
	string token;
	while (std::getline(ss, token, ' '))
	{
		if (token.empty())
			continue;
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Not enough operands");
			int a = _stack.top();
			_stack.pop();
			int b = _stack.top();
			_stack.pop();
			calculator(a, b, token);
		}
		else
		{
			std::istringstream ss(token);
			int val;
			ss >> val;
			if (ss.fail())
				throw std::runtime_error("Failed to convert token to int");
			if (val < 0 || val > 9)
				throw std::runtime_error("Invalid number");
			_stack.push(val);
		}
	}
	if (_stack.size() != 1)
		throw std::runtime_error("Failed to evaluate expression");
	cout << _stack.top() << endl;

}

void RPN::calculator(int a, int b, std::string op) {
	if (op == "+") {
		_stack.push(a + b);
	} else if (op == "-") {
		_stack.push(b - a);
	} else if (op == "*") {
		_stack.push(a * b);
	} else if (op == "/") {
		if (a == 0)
			throw std::runtime_error("Division by zero");
		_stack.push(b / a);
	}
}
