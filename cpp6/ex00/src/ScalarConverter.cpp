#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <cerrno>
#include <bitset>
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other) { (void)other; }
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	if (this != &other)
		(void)other;
	return *this;
}			
ScalarConverter::~ScalarConverter() {}
///////////////////////////////////////////////////////////////////////////////]

///////////////////////////////////////////////////////////////////////////////]
static int	whatIsIt(data& data);
static void printBox(var_box& box);
static void	fillChar(data& data, var_box& box);
static void fillInt(data& data, var_box& box);
static void fillHexa(data& data, var_box& box);
static void fillFloat(data& data, var_box& box);
static void fillDouble(data& data, var_box& box);
///////////////////////////////////////////////////////////////////////////////]

///////////////////////////////////////////////////////////////////////////////]
void ScalarConverter::convert(const std::string& literal) {
	data	data(literal);
	var_box	box;

	switch (whatIsIt(data)) {
		case TYPE_CHAR: fillChar(data, box); break;
		case TYPE_INT: fillInt(data, box); break;
		case TYPE_HEXA: fillHexa(data, box); break;
		case TYPE_FLOAT: fillFloat(data, box); break;
		case TYPE_DOUBLE: fillDouble(data, box); break;
		case TYPE_TOOBIG:
			std::cout << ERR4 "Your input is too long" RESET << std::endl;
			return ;
		case TYPE_INVALID:
			std::cout << ERR4 "Invalid input" RESET << std::endl;
			return ;
		default:
			std::cout << C_243 "You should never see this, meow" RESET << std::endl;
			return ;
	}

	printBox(box);
}
///////////////////////////////////////////////////////////////////////////////]
static int	whatIsIt(data& data) {
	
	if (data._string.length() == 1 && !std::isdigit(data._string[0]))
		return TYPE_CHAR;
	if (!*data._endl)
		return TYPE_INT;
	if (*data._endd == 'f' && !*(data._endd+1))
		return TYPE_FLOAT;
	if (!*data._endd)
		return TYPE_DOUBLE;
	if (!*data._endx)
		return TYPE_HEXA;

	return TYPE_INVALID;
}
///////////////////////////////////////////////////////////////////////////////]
static void printBox(var_box& box) {

	std::cout << std::endl << C_305 "binary: 0b" RESET << std::bitset<8>(box.i) << std::endl;
// 
	std::cout << "\n" << C_451 "char: \t" RESET;
	if (box.control_c)
		std::cout << errors[box.control_c] << std::endl;
	else
		std::cout << C_451 "'" RESET << box.c << C_451 "'" RESET << std::endl;
// 
	std::cout << C_512 "int: \t" RESET;
	if (box.control_i)
		std::cout << errors[box.control_i] << std::endl;
	else
		std::cout << box.i << std::endl;
// 
	std::cout << C_151 "float: \t" RESET;
	if (box.control_f)
		std::cout << errors[box.control_f] << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << box.f << "f" << std::endl;
// 
	std::cout << C_401 "double: " RESET;
	if (box.control_f)
		std::cout << errors[box.control_d] << std::endl;
	else if (box.d < 1e10)
		std::cout << std::fixed << std::setprecision(1) << box.d << std::endl;
	else
		std::cout << box.d << std::endl;
// 
	std::cout << std::endl << C_043 "hexa: \t0x" RESET << std::hex << box.i << std::endl << std::endl;
}
///////////////////////////////////////////////////////////////////////////////]

///////////////////////////////////////////////////////////////////////////////]
static void	fillChar(data& data, var_box& box) {
std::cout << C_550 "\t[ CHAR ]" RESET << std::endl;

	box.c = data._string[0];
	box.i = static_cast<int>(box.c);
	box.f = static_cast<float>(box.c);
	box.d = static_cast<double>(box.c);

}

static void fillInt(data& data, var_box& box) {
std::cout << C_550 "\t[ INT ]" RESET << std::endl;

	box.c = static_cast<char>(data._lng);
	box.i = static_cast<int>(data._lng);
	box.f = static_cast<float>(data._lng);
	box.d = static_cast<double>(data._lng);

	if (data._lng > 255 || data._lng < 0)
		box.control_c = 2;// display Overflow char
	if (!box.control_c && !std::isprint(static_cast<unsigned char>(box.c)))
		box.control_c = 1;//display: Non Displayable char
	
	if (data._lng > INT_MAX || data._lng < INT_MIN)
		box.control_i = 2;// display Overflow int

	if (errno == ERANGE)
		fillDouble(data, box);

}

static void fillHexa(data& data, var_box& box) {
std::cout << C_550 "\t[ HEXA ]" RESET << std::endl;

	unsigned int num = static_cast<unsigned int>(data._hex);
	box.c = static_cast<char>(num);
	box.i = static_cast<int>(num);
	box.f = static_cast<float>(num);
	box.d = static_cast<double>(num);

	if (data._lng > 255 || data._lng < 0)
		box.control_c = 2;// display Overflow char
	if (!box.control_c && !std::isprint(static_cast<unsigned char>(box.c)))
		box.control_c = 1;//display: Non Displayable char
	
	if (data._lng > INT_MAX || data._lng < INT_MIN)
		box.control_i = 2;// display Overflow int

}

static void fillFloat(data& data, var_box& box) {
std::cout << C_550 "\t[ FLOAT ]" RESET << std::endl;

	box.d = static_cast<double>(data._dbl);
	box.f = static_cast<float>(data._dbl);
	box.i = static_cast<int>(data._dbl);
	box.c = static_cast<char>(data._dbl);

	if (data._dbl > 127 || data._dbl < 0)
		box.control_c = 2;// display Overflow char
	if (!box.control_c && !std::isprint(box.c))
		box.control_c = 1;//display: Non Displayable char

	if (data._dbl > INT_MAX || data._dbl < INT_MIN)
		box.control_i = 2;// display Overflow int
	if (std::isnan(data._dbl) || std::isinf(data._dbl)) {
		box.control_c = 4;// display Impossible char
		box.control_i = 4;// display Impossible int
		return ;
	}

	if (data._dbl > FLT_MAX || data._dbl < -FLT_MAX)
		box.control_f = 2;// display Overflow float
	if ((data._dbl > 0 && data._dbl < FLT_MIN) || (data._dbl < 0 && data._dbl > -FLT_MIN))
		box.control_f = 3;// display Min Overflow float

}

static void fillDouble(data& data, var_box& box) {
std::cout << C_550 "\t[ DOUBLE ]" RESET << std::endl;

	box.c = static_cast<char>(data._dbl);
	box.i = static_cast<int>(data._dbl);
	box.f = static_cast<float>(data._dbl);
	box.d = data._dbl;

	if (data._dbl > 127 || data._dbl < 0)
		box.control_c = 2;// display Overflow char
	if (!box.control_c && !std::isprint(box.c))
		box.control_c = 1;//display: Non Displayable char

	if (data._dbl > INT_MAX || data._dbl < INT_MIN)
		box.control_i = 2;// display Overflow int
	if (std::isnan(data._dbl) || std::isinf(data._dbl)) {
		box.control_c = 4;// display Impossible char
		box.control_i = 4;// display Impossible int
		return ;
	}

	if (data._dbl > FLT_MAX || data._dbl < -FLT_MAX)
		box.control_f = 2;// display Overflow float
	if ((data._dbl > 0 && data._dbl < FLT_MIN) || (data._dbl < 0 && data._dbl > -FLT_MIN))
		box.control_f = 3;// display Min Overflow float

	if (errno == ERANGE) {
		box.control_c = 3 + (box.d == 0.0);// display (Small) Overflow char
		box.control_i = box.control_c;
		box.control_f = box.control_c;
		box.control_d = box.control_c;
	}
}
