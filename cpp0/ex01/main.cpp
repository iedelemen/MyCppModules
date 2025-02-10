#include "PhoneBook.hpp"

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1)
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			break;
		}
		std::cout << "Enter command: ";
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit")
			break;
		else if (command == "ADD" || command == "add")
			phoneBook.addContact();
		else if (command == "SEARCH" || command == "search")
			phoneBook.searchContact();
		else
			std::cout << "\033cInvalid command" << std::endl;
	}
	return 0;
}
