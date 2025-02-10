#include "PhoneBook.hpp"
#include <iomanip>

PhoneBook::PhoneBook() : contactCount(0) {}


void	PhoneBook::addContact()
{
	Contact newContact;

	while(newContact.getFirstName().empty()  && !std::cin.eof())
	{
		newContact.setFirstName();
		if (newContact.getFirstName().empty())
			std::cout << "\033cFirst name cannot be empty or invalid character" << std::endl;
		else
			std::cout << "\033c";
	}
	while(newContact.getLastName().empty() && !std::cin.eof())
	{
		newContact.setLastName();
		if (newContact.getLastName().empty())
			std::cout << "\033cLast name cannot be empty or invalid character" << std::endl;
		else
			std::cout << "\033c";
	}
	while(newContact.getNickName().empty() && !std::cin.eof())
	{
		newContact.setNickName();
		if (newContact.getNickName().empty())
			std::cout << "\033cNickname cannot be empty or invalid character" << std::endl;
		else
			std::cout << "\033c";
	}
	while(newContact.getPhoneNumber().empty() && !std::cin.eof())
	{
		newContact.setPhoneNumber();
		if (newContact.getPhoneNumber().empty())
			std::cout << "\033cPhone number cannot be empty or invalid character" << std::endl;
		else
			std::cout << "\033c";
	}
	while(newContact.getDarkSecret().empty() && !std::cin.eof())
	{
		newContact.setDarkSecret();
		if (newContact.getDarkSecret().empty())
			std::cout << "\033cDark secret cannot be empty or invalid character" << std::endl;
		else
			std::cout << "\033c";
	}
	contacts[contactCount] = newContact;
	contactCount++;
	if (contactCount == 8)
		contactCount %= 8;
	std::cout << "\033c";
}

void	PhoneBook::searchContact()
{
	int i = 0;
	std::string index;
	std::cout << "     index|first name| last name|  nickname" << std::endl;
	while (i < 8)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << contacts[i].resizeString(contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << contacts[i].resizeString(contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << contacts[i].resizeString(contacts[i].getNickName()) << std::endl;
		i++;
	}
	std::cout << "Enter index: ";
	std::getline(std::cin, index);
	if (index.length() == 1 && index[0] >= '0' && index[0] <= '7')
	{
		i = index[0] - '0';
		printContact(i);
	}
	else
		std::cout << "Invalid index" << std::endl;
}

void PhoneBook::printContact(int index)
{
	std::cout << "First name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "Last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << contacts[index].getNickName() << std::endl;
	std::cout << "Phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Dark secret: " << contacts[index].getDarkSecret() << std::endl;
}
