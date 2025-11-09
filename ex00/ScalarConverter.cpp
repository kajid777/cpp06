#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>

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
		return (ERROR);
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

void ScalarConverter::convert(const std::string &input) {
    int type;

    type = checkInput(input);
    std::cout << "type: " << type << std::endl;
    
    
}


