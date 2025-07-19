#ifndef AMATERIA_HPP
#define AMATERIA_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <string>
#include <iostream>

#include "../_colors.h"

#include "ICharacter.hpp"
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class AMateria {
private:

protected:
	const std::string	type;

public:
	AMateria(std::string const & type);
	AMateria(const AMateria &other);
	AMateria& operator=(const AMateria& other);
	virtual ~AMateria();
	
	std::string const & getType() const; //Returns the materia type
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

};

#endif

