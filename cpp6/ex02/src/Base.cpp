#include "Base.hpp"

#include <cstdlib>  // for srand, rand
#include <ctime>    // for time

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Base::~Base() {}

///////////////////////////////////////////////////////////////////////////////]
Base *generate( void ) {

	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}

	int random = rand() % 3;
	switch (random) {
		case 0: return new A;
		case 1: return new B;
		case 2: return new C;
		default: return new A;
	}
}

void	identify(Base* p) {

	std::cout << C_414 "Is of type: " RESET;

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << RED "Unknown" RESET << std::endl;
}
void	identify(Base& p) {

}
