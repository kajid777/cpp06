#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

#define NAN_INF 1
#define ERROR 2
#define CHAR 3
#define INT 4
#define FLOAT 5
#define DOUBLE 6

class ScalarConverter {
public:
    static void convert(const std::string &input);

private:
    static int checkInput(const std::string &input);
    static void fromChar(const std::string &input);
    static void fromInt(const std::string &input);
    static void fromFloat(const std::string &input);
    static void fromDouble(const std::string &input);
    ScalarConverter();
    ScalarConverter(const ScalarConverter &);
    ScalarConverter &operator=(const ScalarConverter &);
    ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP


