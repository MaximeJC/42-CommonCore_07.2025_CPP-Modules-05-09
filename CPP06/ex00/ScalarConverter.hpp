#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>
#include <climits>
#include <cstdlib>
#include <limits>
#include <iomanip>

class ScalarConverter {
public:
	static void convert(const std::string& literal);
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void printChar(double value);
	static void printInt(double value);
	static void printFloat(double value);
	static void printDouble(double value);

	static bool isDisplayable(char c);
	static bool isNum(const std::string& literal);
};

#endif
