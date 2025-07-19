#ifndef ICE_HPP
#define ICE_HPP

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
class Ice : public AMateria {

private:

protected:

public:

/////   CANONICAL
	Ice();
	Ice(const Ice &other);
	Ice& operator=(const Ice& other);
	~Ice();

/////
	AMateria*	clone() const;
	void		use(ICharacter& target);

};

#endif

