#include "identify.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* p) {
	if (p == NULL) {
		std::cout << "NULL pointer" << std::endl;
		return;
	}
	
	A* a = dynamic_cast<A*>(p);
	if (a != NULL) {
		std::cout << "A" << std::endl;
		return;
	}
	
	B* b = dynamic_cast<B*>(p);
	if (b != NULL) {
		std::cout << "B" << std::endl;
		return;
	}
	
	C* c = dynamic_cast<C*>(p);
	if (c != NULL) {
		std::cout << "C" << std::endl;
		return;
	}
	
	std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
	try {
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (...) {
	}
	
	try {
		B& b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (...) {
	}
	
	try {
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (...) {
	}
	
	std::cout << "Unknown type" << std::endl;
}

