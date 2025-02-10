#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>

using std::string;

class Contact
{
	private:
		string firstName;
		string lastName;
		string nickName;
		string phoneNumber;
		string darkSecret;

	public:
		string getFirstName();
		string getLastName();
		string getNickName();
		string getPhoneNumber();
		string getDarkSecret();
		string resizeString(string str);

		void setFirstName();
		void setLastName();
		void setNickName();
		void setPhoneNumber();
		void setDarkSecret();
};

#endif

