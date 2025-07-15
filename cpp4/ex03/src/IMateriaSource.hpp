#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
// std::string
// #include <vector>
// #include <map>
// #include <set>
// #include <algorithm>
// #include <cstdlib>
// #include <cmath>
// #include <ctime>
// #include <iomanip>
// #include <sstream>
// #include <utility>
// #include <cassert>
// #include <cctype>
#include "../_colors.h"

#include "AMateria.hpp"
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class IMateriaSource {

public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif

