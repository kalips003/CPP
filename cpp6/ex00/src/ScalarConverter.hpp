#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
enum LiteralType { TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_DOUBLE , TYPE_TOOBIG, TYPE_INVALID};

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
