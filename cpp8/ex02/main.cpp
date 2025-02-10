#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <vector>

int main()
{
	MutantStack<int> mstack;

	mstack.push(10);
	mstack.push(20);
	mstack.push(30);
	mstack.push(40);
	mstack.push(50);

	std::cout << "Top element after pushes: " << mstack.top() << std::endl;
	std::cout << "Stack size after pushes: " << mstack.size() << std::endl;

	mstack.pop();
	std::cout << "Top element after pop: " << mstack.top() << std::endl;
	std::cout << "Stack size after pop: " << mstack.size() << std::endl;

	std::cout << "Elements in the stack (using iterator):" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	MutantStack<int> mstackCopy(mstack);
	std::cout << "Top element of the copied stack: " << mstackCopy.top() << std::endl;

	mstackCopy.pop();
	std::cout << "Top element of the copied stack after pop: " << mstackCopy.top() << std::endl;

	mstack.push(50);
	mstack.push(60);
	mstack.push(70);
	std::cout << "Top element after pushing new values: " << mstack.top() << std::endl;

	std::cout << "Final elements in the stack (using iterator):" << std::endl;
	it = mstack.begin();
	ite = mstack.end();
	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	return 0;

}





