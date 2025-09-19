#include "src/ScalarConverter.hpp"

///////////////////////////////////////////////////////////////////////////////]
// -inff, +inff, -inf, +inf, nan
int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << ERR4 "Wrong number of args" RESET << std::endl;
		return 0; 
	}

	std::string str(av[1]);

	ScalarConverter::convert(str);
	return 0;
}
