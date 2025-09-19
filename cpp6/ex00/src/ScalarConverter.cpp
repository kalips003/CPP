#include "ScalarConverter.hpp"

#include <cctype>
#include <cstdlib>
#include <climits>
#include <iomanip>
#include <cfloat>
#include <cmath>
#include <cerrno>

///////////////////////////////////////////////////////////////////////////////]
static int	whatIsIt(const char* arg);
static void printBox(var_box& box);
static var_box fillChar(const char* arg);
static var_box fillInt(const char * arg);
static var_box fillFloat(const char* arg);
static var_box fillDouble(const char* arg);
static std::string toLower(std::string s) {
    for (std::size_t i = 0; i < s.size(); ++i) {
        s[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(s[i])));
    }
    return s;
}
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
void ScalarConverter::convert(const std::string& literal) {
	const char *str = literal.c_str();

	var_box	box;
	switch (whatIsIt(str)) {
		case TYPE_CHAR: box = fillChar(str); break;
		case TYPE_INT: box = fillInt(str); break;
		case TYPE_FLOAT: box = fillFloat(str); break;
		case TYPE_DOUBLE: box = fillDouble(str); break;
		case TYPE_TOOBIG:
			std::cout << ERR4 "Your input is too big to have any meaningfull sense (> e+19)" RESET << std::endl;
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
///////////////////////////////////////////////////////////////////////////////]
static int	whatIsIt(const char* arg) {
	std::string str = toLower(std::string(arg));
	
	if (str.length() == 1 && !std::isdigit(arg[0]))
		return TYPE_CHAR;

	if (str == "inf" || str == "-inf" || str == "nan")
		return TYPE_DOUBLE;
	if (str == "inff" || str == "-inff")
		return TYPE_FLOAT;

	int start = (str[0] == '-' || str[0] == '+') ? 1 : 0;
	std::size_t dot = str.find('.');
	if (dot == std::string::npos)
		dot = str.size();
	if (dot - start > 19)
		return TYPE_TOOBIG;

	std::strtod(arg, NULL);
	if (errno == ERANGE)
		return TYPE_TOOBIG;

	char *end;
	std::strtol(arg, &end, 10);
	if (!*end)
		return TYPE_INT;

	if (str.find('.') == std::string::npos &&
		str.find('e') == std::string::npos)
		return TYPE_INVALID;

	std::strtod(arg, &end);
	if (*end == 'f' && !*(end+1))
		return TYPE_FLOAT;
	else if (!*end)
		return TYPE_DOUBLE;
	else
		return TYPE_INVALID;
}

static void printBox(var_box& box) {

	std::cout << "\n" << C_451 "char: \t" RESET;
	if (box.control_c)
		std::cout << errors[box.control_c] << std::endl;
	else
		std::cout << "'" << box.c << "'" << std::endl;

	std::cout << C_512 "int: \t" RESET;
	if (box.control_i)
		std::cout << errors[box.control_i] << std::endl;
	else
		std::cout << box.i << std::endl;

	std::cout << C_151 "float: \t" RESET;
	if (box.control_f)
		std::cout << errors[box.control_f] << std::endl;
	else
		std::cout << std::fixed << std::setprecision(1) << box.f << "f" << std::endl;

	if (box.d < 1e10)
		std::cout << C_401 "double: " RESET << std::fixed << std::setprecision(1) << box.d << std::endl << std::endl;
	else
		std::cout << C_401 "double: " RESET << box.d << std::endl << std::endl;
}
///////////////////////////////////////////////////////////////////////////////]
static var_box	fillChar(const char* arg) {
	var_box	box;

	box.c = *arg;
	box.d = static_cast<double>(box.c);
	box.f = static_cast<float>(box.c);
	box.i = static_cast<int>(box.c);

	return box;
}

static var_box fillInt(const char * arg) {
	var_box box;

	// errno = 0;
	long value = std::strtol(arg, NULL, 10);

	box.d = static_cast<double>(value);
	box.f = static_cast<float>(value);
	box.i = static_cast<int>(value);
	box.c = static_cast<char>(value);
	
	if (value > INT_MAX || value < INT_MIN)
		box.control_i = 2;// display Overflow int
	if (value > 255 || value < 0)
		box.control_c = 2;// display Overflow char
	if (!box.control_c && !std::isprint(static_cast<unsigned char>(box.c)))
		box.control_c = 1;//display: Non Displayable char

	if (errno == ERANGE) {
		double security = std::strtod(arg, NULL);
		if (security > FLT_MAX || security < -FLT_MAX)
			box.control_f = 2;// display Overflow float
		else if ((security > 0 && security < FLT_MIN) || (security < 0 && security > -FLT_MIN))
			box.control_f = 3;// display Min Overflow float
		else
			box.f = static_cast<float>(security);
	}

	return box;
}

static var_box fillFloat(const char* arg) {
	var_box box;

	double value = strtod(arg, NULL);

	box.d = static_cast<double>(value);
	box.f = static_cast<float>(value);
	box.i = static_cast<int>(value);
	box.c = static_cast<char>(value);

	// if (value != )
	if (value > FLT_MAX || value < -FLT_MAX)
		box.control_f = 2;// display Overflow float
	if ((value > 0 && value < FLT_MIN) || (value < 0 && value > -FLT_MIN))
		box.control_f = 3;// display Min Overflow float
	if (value > INT_MAX || value < INT_MIN)
		box.control_i = 2;// display Overflow int
	if (value > 127 || value < 0)
		box.control_c = 2;// display Overflow char
	if (!box.control_c && !std::isprint(box.c))
		box.control_c = 1;//display: Non Displayable char

	return box;
}


static var_box fillDouble(const char* arg) {
	var_box box;

	double value = strtod(arg, NULL);
	// value = NaN; -HUGE_VAL;

	box.d = value;
	box.f = static_cast<float>(value);
	box.i = static_cast<int>(value);
	box.c = static_cast<char>(value);

	if (value > FLT_MAX || value < -FLT_MAX)
		box.control_f = 2;// display Overflow float
	if ((value > 0 && value < FLT_MIN) || (value < 0 && value > -FLT_MIN))
		box.control_f = 3;// display Min Overflow float
	if (value > INT_MAX || value < INT_MIN)
		box.control_i = 2;// display Overflow int
	if (value > 127 || value < 0)
		box.control_c = 2;// display Overflow char
	if (!box.control_c && !std::isprint(box.c))
		box.control_c = 1;//display: Non Displayable char

	return box;
}