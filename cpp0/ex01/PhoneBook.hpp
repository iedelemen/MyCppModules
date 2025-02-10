#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact contacts[8];
		int contactCount;
	public:
		PhoneBook();
		void addContact();
		void searchContact();
		void printContact(int index);

};

#endif
