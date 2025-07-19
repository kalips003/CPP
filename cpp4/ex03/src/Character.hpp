#ifndef CHARACTER_HPP
#define CHARACTER_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

#include "AMateria.hpp"
#include "ICharacter.hpp"
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
#define INVENTORY_LIMIT 4
///////////////////////////////////////////////////////////////////////////////]
class Character : public ICharacter {

private:
	std::string name;
	AMateria	*inventory[INVENTORY_LIMIT];
protected:

public:

/////   CANONICAL
	Character(std::string const & name);
	Character(const Character &other);
	Character& operator=(const Character& other);
	~Character();

/////   SETTER GETTER
	std::string const & getName() const;
/////
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

};

#endif

