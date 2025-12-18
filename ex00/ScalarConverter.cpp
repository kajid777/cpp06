#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cfloat>

int	ScalarConverter::checkInput(const std::string &input)
{
	if (input.compare("nan") == 0 || input.compare("+inf") == 0 ||
		input.compare("-inf") == 0 || input.compare("+inff") == 0 ||
		input.compare("-inff") == 0 || input.compare("nanf") == 0)
	{
		return (NAN_INF);
	}
	else if (input.length() == 1 &&
		(input[0] == '+' || input[0] == '-' || // prevents that the input of single digit integers get interpreted as a char
		input[0] == 'f' || input[0] == '.'))
	{
		return (CHAR);
	}
	else if (input.find_first_of("+-") != input.find_last_of("+-")) // catches any multiple or mixed use of + and -
		return (ERROR);//ここはcharじゃないの
	else if (input.find_first_not_of("+-0123456789") == std::string::npos)
		return (INT);
	else if (input.find_first_not_of("+-0123456789.") == std::string::npos)
	{
		if (input.find_first_of(".") != input.find_last_of(".") || // catches `0..0`
			(input.find_first_of(".") != std::string::npos && input.find_first_of(".") + 1 < input.length() && std::isdigit(input[input.find_first_of(".") + 1]) == false) || // catches `0.`
			input.find_first_of(".") == 0) // catches `.0`
			return (ERROR);
		else
			return (DOUBLE);
	}
	else if (input.find_first_not_of("+-0123456789.f") == std::string::npos)
	{
		if (input.find_first_of("f") != input.find_last_of("f") || // catches `0.0ff`
			input.find_first_of(".") != input.find_last_of(".") || // catches `0..0f`
			(input.find_first_of("f") != std::string::npos && input.find_first_of(".") != std::string::npos && input.find_first_of("f") - input.find_first_of(".") == 1) || //catches `0.f`
			input.find_first_of(".") == 0 || // catches `.0f`
			(input.find_first_of("f") != std::string::npos && input.find_first_of("f") + 1 < input.length() && input[input.find_first_of("f") + 1] != '\0')) // catches `0.0f0`
			return (ERROR);
		else
			return (FLOAT);
	}
	else if ((input.length() == 1 && std::isprint(input[0])) ||
		(input.length() == 1 && std::isalpha(input[0])))
	{
		return (CHAR);
	}
	else
		return (ERROR);
}

void ScalarConverter::fromChar(const std::string &input) {
	char charVal = input[0];
	
	if (charVal < 32 || charVal > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << charVal << "'" << std::endl;
	}
	
	std::cout << "int: " << static_cast<int>(charVal) << std::endl;
	std::cout << "float: " << static_cast<float>(charVal) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(charVal) << ".0" << std::endl;
}

void ScalarConverter::fromInt(const std::string &input) {
	long intVal = std::strtol(input.c_str(), NULL, 10);
	
	if (intVal < CHAR_MIN || intVal > CHAR_MAX) {
		std::cout << "char: impossible" << std::endl;
	} else if (intVal < 32 || intVal > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(intVal) << "'" << std::endl;
	}
	
	if (intVal < INT_MIN || intVal > INT_MAX) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(intVal) << std::endl;
	}
	
	std::cout << "float: " << static_cast<float>(intVal) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(intVal) << ".0" << std::endl;
}

void ScalarConverter::fromFloat(const std::string &input) {
	std::string floatStr = input;
	if (floatStr[floatStr.length() - 1] == 'f') {
		floatStr = floatStr.substr(0, floatStr.length() - 1);
	}
	
	float floatVal = std::strtof(floatStr.c_str(), NULL);
	
	if (floatVal < CHAR_MIN || floatVal > CHAR_MAX || floatVal != floatVal) {
		std::cout << "char: impossible" << std::endl;
	} else if (floatVal < 32 || floatVal > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(floatVal) << "'" << std::endl;
	}
	
	if (floatVal < INT_MIN || floatVal > INT_MAX || floatVal != floatVal) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(floatVal) << std::endl;
	}
	
	std::cout << "float: " << floatVal << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(floatVal) << std::endl;
}

void ScalarConverter::fromDouble(const std::string &input) {
	double doubleVal = std::strtod(input.c_str(), NULL);
	
	if (doubleVal < CHAR_MIN || doubleVal > CHAR_MAX || doubleVal != doubleVal) {
		std::cout << "char: impossible" << std::endl;
	} else if (doubleVal < 32 || doubleVal > 126) {
		std::cout << "char: Non displayable" << std::endl;
	} else {
		std::cout << "char: '" << static_cast<char>(doubleVal) << "'" << std::endl;
	}
	
	if (doubleVal < INT_MIN || doubleVal > INT_MAX || doubleVal != doubleVal) {
		std::cout << "int: impossible" << std::endl;
	} else {
		std::cout << "int: " << static_cast<int>(doubleVal) << std::endl;
	}
	
	std::cout << "float: " << static_cast<float>(doubleVal) << "f" << std::endl;
	std::cout << "double: " << doubleVal << std::endl;
}

void ScalarConverter::fromNanInf(const std::string &input) {
	// nan / inf 系はすべて「表示不可能 or 不可能」扱い
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;

	// 入力が nan / +inf / -inf / nanf / +inff / -inff のいずれか
	std::string floatStr = input;
	std::string doubleStr = input;

	// f が付いていない場合: float 表示用に f を付け、double はそのまま
	if (input == "nan" || input == "+inf" || input == "-inf") {
		floatStr = input + "f";     // 例: nan → nanf
		doubleStr = input;          // 例: nan
	}
	// f が付いている場合: double 表示用に f を外す
	else if (input == "nanf" || input == "+inff" || input == "-inff") {
		floatStr = input;                          // 例: nanf
		doubleStr = input.substr(0, input.size()-1); // 例: nanf → nan
	}

	std::cout << "float: " << floatStr << std::endl;
	std::cout << "double: " << doubleStr << std::endl;
}

void ScalarConverter::convert(const std::string &input) {
    int type;

    type = checkInput(input);
    std::cout << "type: " << type << std::endl;
	
    if (type == CHAR) {
        fromChar(input);
    } else if (type == INT) {
        fromInt(input);
    } else if (type == FLOAT) {
        fromFloat(input);
    } else if (type == DOUBLE) {
        fromDouble(input);
    } else if (type == NAN_INF) {
        fromNanInf(input);
    }
}


