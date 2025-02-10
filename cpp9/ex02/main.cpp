#include "PmergeMe.hpp"

int main(int ac, char **arv)
{
	if (ac < 3) {
		std::cerr << "usage: ./PmergeMe [expression]" << std::endl;
		return 1;
	}

	try {
		PmergeMe merge(arv);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
