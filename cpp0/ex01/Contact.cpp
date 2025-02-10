#include "Contact.hpp"

string Contact::getFirstName()
{
	return firstName;
}

string Contact::getLastName()
{
	return lastName;
}

string Contact::getNickName()
{
	return nickName;
}

string Contact::getPhoneNumber()
{
	return phoneNumber;
}

string Contact::getDarkSecret()
{
	return darkSecret;
}


void Contact::setFirstName()
{
	std::cout << "Enter first name: ";
	std::getline(std::cin, firstName);

	for (size_t i = 0; i < firstName.length(); i++)
	{
		if (!isalnum(firstName[i])) {
			firstName.clear();
			return ;
		}
	}
}

void Contact::setLastName()
{
	std::cout << "Enter last name: ";
	std::getline(std::cin, lastName);
	for (size_t i = 0; i < lastName.length(); i++)
	{
		if (!isalnum(lastName[i])) {
			lastName.clear();
			return ;
		}
	}
}

void Contact::setNickName()
{
	std::cout << "Enter nickname: ";
	std::getline(std::cin, nickName);
	for (size_t i = 0; i < nickName.length(); i++)
	{
		if (!isalnum(nickName[i])) {
			nickName.clear();
			return ;
		}
	}
}

void Contact::setPhoneNumber()
{
	std::cout << "Enter phone number: ";
	std::getline(std::cin, phoneNumber);
	for (size_t i = 0; i < phoneNumber.length(); i++)
	{
		if (!isalnum(phoneNumber[i])) {
			phoneNumber.clear();
			return ;
		}
	}
}
void Contact::setDarkSecret()
{
	std::cout << "Enter dark secret: ";
	std::getline(std::cin, darkSecret);
	for (size_t i = 0; i < darkSecret.length(); i++)
	{
		if (!isalnum(darkSecret[i])) {
			darkSecret.clear();
			return ;
		}
	}
}

string Contact::resizeString(string str)
{
	if (str.length() > 10)
	{
		str.resize(9);
		str += ".";
	}
	return str;
}
