#include <iostream>

using std::string;

int main()
{
	string stringNOR = "HI THIS IS BRAIN";
	string* stringPTR = &stringNOR;
	string& stringREF = stringNOR;

	std::cout << &stringNOR << std::endl;
	std::cout << stringPTR << std::endl;
	std::cout << &stringREF << std::endl;

	std::cout << stringNOR << std::endl;
	std::cout << *stringPTR << std::endl;
	std::cout << stringREF << std::endl;

}
