#include "BitcoinExchange.hpp"

std::string ft_trim(const std::string& str) {
	size_t first = str.find_first_not_of(" \t");
	if (first == std::string::npos)
		return "";
	size_t last = str.find_last_not_of(" \t");
	return str.substr(first, (last - first + 1));
}

int main(int argc, char** argv) {
	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}

	try {
		BitcoinExchange btcExchange("data.csv");
		std::ifstream input_file(argv[1]);
		if (!input_file.is_open())
			throw std::string("Can't open input file");
		std::string line;
		while (std::getline(input_file, line))
		{
			try {
				size_t vbarPos = line.find('|');
				if (vbarPos == std::string::npos) {
					throw std::string("Bad input => " + line);
				}
				std::string date = ft_trim(line.substr(0, vbarPos));
				if (date == "date") {
					continue;
				}
				if (BitcoinExchange::checkDate(date) != "")
					throw std::string(BitcoinExchange::checkDate(date));
				std::string valueStr = ft_trim(line.substr(vbarPos + 1));
				if (valueStr.empty()) {
					throw std::string("Missing value for date => " + date);
				}
				float value = std::atof(valueStr.c_str());
				if (value < 0 || value > 1000) {
					throw std::string("Value (" + ft_trim(valueStr) + ") has to be between 0.0 and 1000.0");
				}
				std::cout << date << " => " << value << " = " << value * btcExchange.getExchangeRate(date) << std::endl;
			} catch (const std::string& e) {
				std::cerr << "Error: " << e << std::endl;
			}
		}
		input_file.close();
	} catch (const std::string& e) {
		std::cerr << "Error: " << e << std::endl;
		return 1;
	}

	return 0;
}
