#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(const std::string& dataFile) {
	std::ifstream file(dataFile.c_str());
	if (!file.is_open()) {
		throw std::string("Could not open data file: " + dataFile);
	}

	std::string line;
	while (std::getline(file, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			continue;
		}
		std::string date = line.substr(0, commaPos);
		if (date == "date" || checkDate(date) != "") {
			continue;
		}
		float rate = std::atof(line.substr(commaPos + 1).c_str());
		if (rate < 0) {
			continue;
		}
		_exchangeRates[date] = rate;
	}
	file.close();
	std::cout << "Database loaded with " << _exchangeRates.size() << " entries." << std::endl;
}

std::string BitcoinExchange::checkDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return std::string("Invalid date format (YYYY-MM-DD) => ") + date;
	}
	for (size_t i = 0; i < date.length(); ++i) {
		if (i == 4 || i == 7) continue;
		if (!isdigit(date[i])) {
			return std::string("Invalid date format (YYYY-MM-DD) => ") + date;
		}
	}
	int year = atoi(date.substr(0, 4).c_str());
	int month = atoi(date.substr(5, 2).c_str());
	int day = atoi(date.substr(8, 2).c_str());
	if (year < 2009 || (year == 2009 && month == 1 && day == 1))
		return std::string("Invalid date (Bitcoin didn't exist before 2009-01-02) => ") + date;
	if (year > 2025)
		return std::string("Invalid date (Can't predict it's exchange rate in the future) => ") + date;
	if (month < 1 || month > 12 ||
		day < 1 || day > 31) {
		return std::string("Invalid date => ") + date;
	}
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30)
			return std::string("Invalid date => ") + date;
	} else if (month == 2) {
		if (day > 29)
			return std::string("Invalid date => ") + date;
		if (day == 29 && !(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)))
			return std::string("Invalid date (not leap year) => ") + date;
	}
	return "";
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
	std::map<std::string, float>::const_iterator it = _exchangeRates.find(date);
	if (it != _exchangeRates.end()) {
		return it->second;
	}
	it = _exchangeRates.lower_bound(date);
	if (it != _exchangeRates.end()) {
		if (it->first == date) {
			return it->second;
		}
		if (it != _exchangeRates.begin()) {
			--it;
			return it->second;
		}
	}
	return -1;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	*this = other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other) {
		_exchangeRates = other._exchangeRates;
	}
	return *this;
}
