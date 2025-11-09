#include "ScalarConverter.hpp"
#include <string>
#include <iostream>

int main(int argc, char **argv) {
    if (argc == 2) {
        ScalarConverter::convert(std::string(argv[1]));
    } else {
        std::cout << "引数は一つだけ指定してください" << std::endl;
        return 1;
    }
    return 0;
}


