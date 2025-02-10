#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "--Debug--" << std::endl;
	std::cout << "I love extra bacon." << std::endl;
}
void Harl::info(void)
{
	std::cout << "--Info--" << std::endl;
	std::cout << "Adding extra bacon costs more." << std::endl;
}
void Harl::warning(void)
{
	std::cout << "--Warning--" << std::endl;
	std::cout << "Eat too much bacon and you'll get fat." << std::endl;
}
void Harl::error(void)
{
	std::cout << "--Error--" << std::endl;
	std::cout << "You can't have bacon without a burger." << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*ptr[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string _level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i = 0;
	while ( i < 4 && _level[i].compare(level))
		i++;
	if (i == 4)
	{
		std::cerr << "Wrong Argument. Please enter DEBUG, INFO, WARNING or ERROR." << std::endl;
		return;
	}
	(this->*ptr[i])();

}
