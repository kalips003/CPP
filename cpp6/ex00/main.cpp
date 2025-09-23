#include "src/ScalarConverter.hpp"

///////////////////////////////////////////////////////////////////////////////]
static std::string toLower(std::string s) {
    for (std::size_t i = 0; i < s.size(); ++i) {
        s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
    }
    return s;
}

///////////////////////////////////////////////////////////////////////////////]
// -inff, +inff, -inf, +inf, nan
int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << ERR4 "Wrong number of args" RESET << std::endl;
		return 0; 
	}

	std::string str = toLower(std::string(av[1]));

	ScalarConverter::convert(str);
	return 0;
}
