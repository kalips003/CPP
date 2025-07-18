#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

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
