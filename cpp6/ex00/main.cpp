#include "src/ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>
///////////////////////////////////////////////////////////////////////////////]
enum LiteralType { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_INVALID };
// ptr function { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE, TYPE_INVALID };
// std::stringstream	f_char() {}
// std::stringstream	f_int() {}
// std::stringstream	f_float() {}
// std::stringstream	f_double() {}
///////////////////////////////////////////////////////////////////////////////]
int	whatIsIt(const char* arg) {

	if (std::string(arg).length() == 1 && !std::isdigit(arg[0]))
		return TYPE_CHAR;

	char *end;
	std::strtol(arg, &end, 10);
	if (!*end)
		return TYPE_INT;

	if (std::string(arg).find('.') == std::string::npos &&
		std::string(arg).find('e') == std::string::npos)
		return TYPE_INVALID;

	std::strtod(arg, &end);
	if (*end == 'f' && !*(end+1))
		return TYPE_FLOAT;
	else if (!*end)
		return TYPE_DOUBLE;
	else
		return TYPE_INVALID;
}

///////////////////////////////////////////////////////////////////////////////]
const char* typeName(int type) {
	switch (type) {
		case TYPE_CHAR: return "TYPE_CHAR";
		case TYPE_INT: return "TYPE_INT";
		case TYPE_FLOAT: return "TYPE_FLOAT";
		case TYPE_DOUBLE: return "TYPE_DOUBLE";
		case TYPE_INVALID: return "TYPE_INVALID";
		default: return "UNKNOWN";
	}
}

///////////////////////////////////////////////////////////////////////////////]
// 
void	rtrnChar(char *arg) {
	std::cout << C_124 "char: \t" RESET;

	char c(arg[0]);
	if (arg[1])
		std::cout << RED "Impossible" RESET;
	else if (std::isprint(c) && !std::isdigit(c))
		std::cout << "'" << c << "'";
	else
		std::cout << RED "Non displayable" RESET;
	std::cout << std::endl;
}


void	rtrnInt(char *arg) {
	std::cout << C_135 "int: " RESET;

	long long l = strtol(arg, NULL, 10);
	if (l > INT_MAX || l < INT_MIN)
		std::cout << C_400 "Too big" RESET;
	std::cout << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
template <typename T>
void	convertion(T num) {
	char c = static_cast<char>(num);
	int i = static_cast<int>(num);
	float f = static_cast<float>(num);
	double d = static_cast<double>(num);

	std::cout << C_454 "char: \t" RESET << c << std::endl;
	std::cout << C_512 "int: \t" RESET << i << std::endl;
	std::cout << C_153 "float: \t" RESET << f << "f" << std::endl;
	std::cout << C_401 "double: " RESET << d << std::endl;
	std::cout << C_454 "char again int?: \t" RESET << static_cast<int>(c) << std::endl;

}

///////////////////////////////////////////////////////////////////////////////]
void	doThePrinting(char *arg) {
	std::cout << std::endl;
	rtrnChar(arg);
	std::cout << C_512 "int: \t" RESET << std::atoi(arg) << std::endl;
	std::cout << C_153 "float: \t" RESET << std::strtof(arg, NULL) << std::endl;
	std::cout << C_401 "double: " RESET << std::strtod(arg, NULL) << std::endl;
	std::cout << C_124 "binary: " RESET << std::strtol(arg, NULL, 2) << std::endl;
	std::cout << C_201 "hexa: \t" RESET << std::strtol(arg, NULL, 16) << std::endl;
}
///////////////////////////////////////////////////////////////////////////////]
// -inff, +inff, -inf, +inf, nan
int main(int ac, char** av) {
	if (ac != 2) {
		std::cout << ERR4 "Wrong number of args" RESET << std::endl;
		return 0; 
	}
	std::cout << C_401 "double= " RESET << std::fixed << std::setprecision(1) << static_cast<double>('*') << std::endl;
	std::cout << C_401 "double= " RESET << std::fixed << std::setprecision(1) << 42.123 << std::endl;

	std::cout << C_232 "The arg is of type: " RESET << typeName(whatIsIt(av[1])) << std::endl << std::endl;

	std::cout << C_430 "\e[4m" "\tDo the printing:" RESET;
	doThePrinting(av[1]);



	std::cout << std::endl;
	std::cout << C_430 "\e[4m" "\tConversion:" RESET;
	std::cout << std::endl;
	convertion(std::strtod(av[1], NULL));

	return 0;
}

