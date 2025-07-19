#include "Character.hpp"


///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Character::Character(std::string const & name)
 : name(name) {
	for (int i = 0; i < INVENTORY_LIMIT; i++)
		inventory[i] = NULL;
}
Character::Character(const Character &other)
 : name(other.name) {
	for (int i = 0; i < INVENTORY_LIMIT; i++) {
		if (other.inventory[i])
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}
Character& Character::operator=(const Character& other) {
	if (this != &other) {
		name = other.name;
		for (int i = 0; i < INVENTORY_LIMIT; i++) {
			delete inventory[i];
			if (other.inventory[i])
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}
	return *this;
}
Character::~Character() {
	for (int i = 0; i < INVENTORY_LIMIT; i++)
		delete inventory[i];
}
///////////////////////////////////////////////////////////////////////////////]
std::string const & Character::getName() const {
	return name;
}
///////////////////////////////////////////////////////////////////////////////]
void Character::equip(AMateria* m) {
	if (!m) {
		std::cout << RED "How do you expect me to equip NOTHING?!?" RESET << std::endl;
		return;
	}
	for (int i = 0; i < INVENTORY_LIMIT; i++) {
		if (inventory[i] == m) {
			std::cout << C_215 << "Already equiped" << RESET << std::endl;
			return;
		}
	}
	for (int i = 0; i < INVENTORY_LIMIT; i++) {
		if (!inventory[i]) {
			inventory[i] = m;
			return;
		}
	}
	std::cout << C_513 << "Inventory full!" << RESET << std::endl;
}
void Character::unequip(int idx) {
	if (idx >= INVENTORY_LIMIT || idx < 0)
		return;
	inventory[idx] = NULL;
}
void Character::use(int idx, ICharacter& target) {
	if (idx >= INVENTORY_LIMIT || idx < 0 || !inventory[idx]) {
		std::cout << RED "im sorry i cant do that" RESET << std::endl;
		return;
	}
	std::cout << name << ": ";
	inventory[idx]->use(target);
}
