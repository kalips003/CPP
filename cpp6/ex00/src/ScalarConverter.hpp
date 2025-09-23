#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
#include <cerrno>
#include <limits>

#include <cstdlib>
#include <cstring>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
enum LiteralType { TYPE_CHAR, TYPE_INT, TYPE_HEXA, TYPE_FLOAT, TYPE_DOUBLE , TYPE_TOOBIG, TYPE_INVALID};

struct var_box {
	double	d;
	float	f;
	int		i;
	char	c;

	signed char	control_d;
	signed char	control_f;
	signed char	control_i;
	signed char	control_c;

	var_box() : d(0), f(0), i(0), c(0),
		control_d(0), control_f(0), control_i(0), control_c(0) {}

};

// _literal is in lowercase already
struct data {
	const std::string&	_string;
	const char*			_strPtr;
	char 			*_endd;
	double			_dbl;
	char 		*_endl;
	long		_lng;
	char 		*_endx;
	long		_hex;

	data(const std::string&	literal) : _string(literal) {
		_strPtr = literal.c_str();
		_lng = std::strtol(_strPtr, &_endl, 10);
		_hex = std::strtol(_strPtr, &_endx, 16);
		_dbl = std::strtod(_strPtr, &_endd);
	}
};

const std::string errors[5] = {
	"You should never see this.",
	"Non Displayable",
	"Overflow",
	"Small Overflow",
	"Impossible"
};
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class ScalarConverter {

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter& operator=(const ScalarConverter& other);

protected:

public:


/////   CANONICAL
	~ScalarConverter();

/////
	static void convert(const std::string & literal);

};

#endif
