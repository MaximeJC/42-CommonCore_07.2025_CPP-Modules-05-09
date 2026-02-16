#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void ScalarConverter::convert(const std::string& literal) {
	try {
		double d;
		if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
			d = static_cast<double>(literal[0]);
		else if (literal.length() == 3 && (literal[0] == '"' || literal[2] == '\'') && literal[0] == literal[2]
			&& std::isprint(literal[1]))
			d = static_cast<double>(literal[1]);
		else if (isNum(literal))
			d = std::strtod(literal.c_str(), NULL);
		else if (literal == "nan" || literal == "nanf")
			d = nan("");
		else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
			d = std::numeric_limits<double>::infinity();
		else if (literal == "-inf" || literal == "-inff")
			d = -std::numeric_limits<double>::infinity();
		else
			throw std::invalid_argument("Invalid literal");
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
	} catch (const std::exception& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}

void ScalarConverter::printChar(double value) {
	std::cout << "char: ";
	if (std::isnan(value) || value < 0 || value > 127)
		std::cout << "impossible" << std::endl;
	else {
		char c = static_cast<char>(value);
		if (isDisplayable(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
}

void ScalarConverter::printInt(double value) {
	std::cout << "int: ";
	if (std::isnan(value) || value < static_cast<double>(INT_MIN) || value > static_cast<double>(INT_MAX))
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
	std::cout << "float: ";
	if (std::isnan(value))
		std::cout << "nanf" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inf" << std::endl;
	else if (value < -FLT_MAX || value > FLT_MAX)
		std::cout << "impossible" << std::endl;
	else {
		float f = static_cast<float>(value);
		std::cout << std::fixed << std::setprecision(1) << f;
		std::cout << "f" << std::endl;
	}
}

void ScalarConverter::printDouble(double value) {
	std::cout << "double: ";
	if (std::isnan(value))
		std::cout << "nan" << std::endl;
	else if (value == std::numeric_limits<double>::infinity())
		std::cout << "inf" << std::endl;
	else if (value == -std::numeric_limits<double>::infinity())
		std::cout << "-inf" << std::endl;
	else if (value < -DBL_MAX || value > DBL_MAX)
		std::cout << "impossible" << std::endl;
	else {
		std::cout << std::fixed << std::setprecision(1) << value;
		std::cout << std::endl;
	}
}

bool ScalarConverter::isDisplayable(char c) {
	return std::isprint(static_cast<unsigned char>(c));
}

bool ScalarConverter::isNum(const std::string& literal) {
	size_t i = 0;
	bool hasDecimal = false;
	if (literal[i] == '-' || literal[i] == '+')
		i++;
	if (i == literal.length())
		return false;
	for (; i < literal.length(); i++) {
		if (!std::isdigit(literal[i])) {
			if (literal[i] == '.' && !hasDecimal) {
				hasDecimal = true;
				continue;
			}
			if (literal[i] == 'f' && i == literal.length() - 1)
				return hasDecimal;
			return false;
		}
	}
	return true;
}
