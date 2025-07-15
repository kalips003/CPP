#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

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
#include "IMateriaSource.hpp"
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
#define MEMORY_LIMIT 4
///////////////////////////////////////////////////////////////////////////////]
class MateriaSource : public IMateriaSource {

private:
	AMateria	*memory[MEMORY_LIMIT];
protected:

public:

/////   CANONICAL
	MateriaSource();
	MateriaSource(const MateriaSource &other);
	MateriaSource& operator=(const MateriaSource& other);
	~MateriaSource();

/////
	void learnMateria(AMateria*);
	AMateria* createMateria(std::string const & type);

};

#endif