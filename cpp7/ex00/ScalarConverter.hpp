#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cctype>
#include <sstream>


using std::string;
using std::cout;
using std::endl;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		~ScalarConverter();
		ScalarConverter &operator=(const ScalarConverter &obj);
	public:

		static void convert(const string &input);

};


#endif
