#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {}
		MutantStack(const MutantStack &mstack) : std::stack<T>(mstack) {}
		~MutantStack() {}
		MutantStack &operator=(const MutantStack &mstack)
		{
			if (this == &mstack)
				return *this;
			std::stack<T>::operator=(mstack);
			return *this;
		}

		typedef typename std::deque<T>::iterator iterator;

		iterator begin() { return std::stack<T>::c.begin();}

		iterator end() { return std::stack<T>::c.end();}

};

#endif


