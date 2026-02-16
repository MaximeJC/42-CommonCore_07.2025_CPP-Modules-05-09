#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <cstdlib>
#include <iomanip>

class BitcoinExchange {
public:
	BitcoinExchange(const std::string& dataFile);
	~BitcoinExchange();
	static std::string checkDate(const std::string& date);
	float getExchangeRate(const std::string& date) const;
	private:
	std::map<std::string, float> _exchangeRates;

	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
};

#endif
