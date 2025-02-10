#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	for (int i = 0; i <= 5; i++)
		v.push_back(i);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Not found" << std::endl;
	}

	return 0;
}
