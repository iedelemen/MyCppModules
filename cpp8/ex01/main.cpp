#include "Span.hpp"

int main()
{
	try {
	Span sp = Span(10);
	// sp.addNumber(6);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	sp.improveAddNumber(1, 10);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Span is full!" << std::endl;
	}
	return 0;
}
