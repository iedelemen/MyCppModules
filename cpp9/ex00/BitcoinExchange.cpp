#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	std::ifstream dataFile("data.csv");
	if (!dataFile.is_open())
		throw std::runtime_error("Could not open file");
	string line;
	std::getline(dataFile, line);
	if (line.empty())
		throw std::runtime_error("Data file is empty");

	string date;
	string value;
	size_t buf;
	while (std::getline(dataFile, line) && !line.empty())
	{
		buf = line.find(',');
		date = line.substr(0, buf);
		value = line.substr(buf + 1);
		std::istringstream ss(value);
		double val;
		ss >> val;
		_dataBase[date] = val;
	}
	dataFile.close();

}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {*this = other;}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		_dataBase = other._dataBase;
	return *this;
}

void BitcoinExchange::readFile(const string &filename)
{
	std::ifstream file(filename.c_str());
	if (!file.is_open())
		throw std::runtime_error("Could not open file");
	string header;
	std::getline(file, header);
	if (header != "date | value")
		throw std::runtime_error("Invalid header format (date | value)");

	string line;
	while (std::getline(file, line))
	{
		string date;
		string quantity;
		size_t buf;

		if (checkFile(line))
			continue;
		buf = line.find('|');
		date = line.substr(0, buf);
		quantity = line.substr(buf + 1);
		std::istringstream ss(quantity);
		double val;
		ss >> val;

		map<string, double>::iterator it = _dataBase.lower_bound(date);
		if (it == _dataBase.end() || it->first != date)
		{
			if (it != _dataBase.begin())
				--it;
			else
			{
				cout << " No data" << endl;
				continue;
			}
		}
		std::cout << date << ": " << val << " Btc" << " = " << it->second * val << std::endl;

	}
	file.close();

}

int BitcoinExchange::checkFile(const string &file)
{
	size_t pos = file.find('|');
	if (pos == string::npos)
		return cout << "Invalid line: " << file << endl, 1;
	string date = file.substr(0, pos);
	if (date.find_first_not_of("0123456789- ") != string::npos)
		return cout << "Invalid date: " << date << endl, 1;

	string quantity = file.substr(pos + 1);
	if (quantity.find_first_not_of("0123456789. ") != string::npos)
		return cout << "Invalid quantity: " << quantity << endl, 1;

	std::istringstream ss(quantity);
	double qua;
	ss >> qua;
	if (qua < 0)
		return cout << "Number of btc can't be negative!" << endl, 1;
	if (qua > 1000)
		return cout << "Number of btc can't be more than 1000!" << endl, 1;

	std::istringstream ss2(date);
	int day, month, year;
	char c;
	ss2 >> year >> c >> month >> c >> day;
	if (year < 2010 || year > 2021)
		return cout << "Invalid year: " << year << endl, 1;
	if (month < 1 || month > 12)
		return cout << "Invalid month: " << month << endl, 1;
	if (day < 1 || day > 31)
		return cout << "Invalid day: " << day << endl, 1;

	bool leap = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
	if (month == 2 && (day > 28 + leap || day < 1))
		return cout << "Invalid day: " << day << endl, 1;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && (day > 30 || day < 1))
		return cout << "Invalid day: " << day << endl, 1;
	if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && (day > 31 || day < 1))
		return cout << "Invalid day: " << day << endl, 1;


	return 0;
}
