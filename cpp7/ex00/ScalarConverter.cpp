#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	*this = obj;
}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj)
{
	if (this == &obj)
		return *this;
	return *this;
}

void ScalarConverter::convert(const std::string &input)
{
	if (input == "-inff" || input == "+inff" || input == "nanf" ||
	input == "-inf" || input == "+inf" || input == "nan")
	{
		cout << "input is a pseudo literal" << endl;
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << std::fixed << std::setprecision(2);
		if (input[input.size()- 1] == 'f' && (input != "-inf" && input != "+inf"))
		{
			std::cout << "float: " << input << std::endl;
			std::cout << "double: " << input.substr(0, input.size() - 1) << std::endl;
		}
		else
		{
			std::cout << "float: " << input << "f" << std::endl;
			std::cout << "double: " << input << std::endl;
		}
		return;
	}
	if (input.length() == 1 && !isdigit(input[0]))
	{
		cout << "input is a char" << endl;
		char c = input[0];
		std::cout << "char: '" << c << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(c) << std::endl;
		std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}

	std::istringstream iss(input);
	int i;

	if ((input.find('.') == std::string::npos && input.find('f') == std::string::npos)&& iss >> i)
	{
		cout << "input is an int" << endl;
		std::cout << "char: ";
		if (i < 32 || i > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(i) << "'" << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << std::endl;
		return;
	}

	iss.clear();
	iss.str(input);

	float f;
	if (input.find('f') != std::string::npos && iss >> f)
	{
		cout << "input is a float" << endl;
		std::cout << "char: ";
		if (f < 32 || f > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(f) << "'" << std::endl;
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "int: " << static_cast<int>(f) << std::endl;
		std::cout << "float: " << f << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(f) << std::endl;
		return;
	}

	iss.clear();
	iss.str(input);

	double d;
	if (iss >> d)
	{
		cout << "input is a double" << endl;
		std::cout << "char: ";
		if (d < 32 || d > 126)
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		std::cout << std::fixed << std::setprecision(2);
		std::cout << "int: " << static_cast<int>(d) << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
		std::cout << "double: " << d << std::endl;
		return;
	}

	std::cout << "Conversion impossible" << std::endl;
}
