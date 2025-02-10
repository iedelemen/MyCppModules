#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using std::string;
using std::map;
using std::cout;
using std::endl;

class BitcoinExchange
{
	private:
		map<string, double> _dataBase;

	public:
		BitcoinExchange();
		~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);

		void readFile(const string &filename);
		int checkFile(const string &line);

};

#endif
