#include "RPN.hpp"

int main(int ac, char **arv)
{
	if (ac != 2) {
		std::cerr << "usage: ./rpn [expression]" << std::endl;
		return 1;
	}

	try {
		RPN rpn(arv[1]);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
