#include "ClapTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
ClapTrap::ClapTrap( const std::string& name )
: name(name), hp(10), energy(10), attack_dmg(0) {
    std::cout << C_041 << "Default constructor called" << RESET << std::endl;
}
ClapTrap::~ClapTrap( void ) {
    std::cout << C_401 << "Destructor called" << RESET << std::endl;
}
ClapTrap::ClapTrap( const ClapTrap& other )
: name(other.name), hp(other.hp), energy(other.energy), attack_dmg(other.attack_dmg) {
    std::cout << C_042 << "Copy constructor called" << RESET << std::endl;
}
ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
    std::cout << C_141 << "Copy assignment operator called" << RESET << std::endl;
	hp = other.hp;
	energy = other.energy;
	attack_dmg = other.attack_dmg;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////]
void ClapTrap::attack( const std::string& target ) {
	if (!hp || !energy) {
		std::cout << C_400 << name << " can't attack..." RESET << std::endl;
		return;
	}
	std::cout << C_152 "ClapTrap " << name << " attacks " C_541 << target << 
	C_152 ", causing " RESET << attack_dmg << C_152 " points of damage!" RESET << std::endl;
	energy--;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (!amount) {
		std::cout << C_040 "ClapTrap " << name << " takes no damages!" RESET << std::endl;
		return;
	}
	std::cout << C_512 "ClapTrap " << name << " takes " RED << amount << C_512 " points of damage!" << std::endl;
	if (!hp) {
		std::cout << RED "\tStop it! Stop! Its already dead..." RESET << std::endl;
		return;
	}
	hp -= amount;
	hp = hp < 0 ? 0 : hp;
	if (!hp)
		std::cout << RED "\t" << name << " fainted!" RESET << std::endl;
	else
		std::cout << "remaining: " RESET << hp << C_512 " hp" RESET << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (!amount) {
		std::cout << C_400 << "ClapTrap " << name << " can't heal!" << RESET << std::endl;
		return;
	}
	if (!hp || !energy) {
		std::cout << C_400 << name << " is out of energy!" << RESET << std::endl;
		return;
	}
	std::cout << C_152 << "ClapTrap " << name << " repairs itself for " RESET << amount << 
	C_152 " hp! " RESET << std::endl;
	hp += amount;
	std::cout << C_152 "remaining: " RESET << hp << C_152 " hp" RESET << std::endl;
	energy--;
}
