#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
using std::cout;
using std::endl;
using std::string;
#include <stack>
using std::stack;
#include <sstream>


class RPN
{
	private:
		stack<int> _stack;
		
	public:
		RPN(string arg);
		~RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);

		void calculator(int a, int b, string op);
		void check(string arg);

};

#endif
