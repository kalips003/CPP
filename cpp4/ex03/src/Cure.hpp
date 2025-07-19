#ifndef CURE_HPP
#define CURE_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

#include "ICharacter.hpp"
#include "AMateria.hpp"

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class Cure : public AMateria {

private:

protected:

public:

/////   CANONICAL
	Cure();
	Cure(const Cure &other);
	Cure& operator=(const Cure& other);
	~Cure();

/////
	AMateria*	clone() const;
	void		use(ICharacter& target);

};

#endif

