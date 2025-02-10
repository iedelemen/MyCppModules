#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "usage: ./btc [filename]" << std::endl;
		return 1;
	}
	try
	{
		BitcoinExchange exchange;
		exchange.readFile(av[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
