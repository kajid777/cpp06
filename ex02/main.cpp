#include "generate.hpp"
#include "identify.hpp"
#include <iostream>

int main() {
	Base* ptr = generate();
	
	std::cout << "=== Testing identify(Base*) ===" << std::endl;
	std::cout << "ptr: ";
	identify(ptr);
	
	std::cout << std::endl << "=== Testing identify(Base&) ===" << std::endl;
	std::cout << "*ptr: ";
	identify(*ptr);
	
	delete ptr;
	
	return 0;
}

