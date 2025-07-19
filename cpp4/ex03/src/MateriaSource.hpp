#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

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