#include "ClapTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
ClapTrap::ClapTrap( const std::string& name )
: name(name), hp(100), energy(50), attack_dmg(20) {
    std::cout << C_041 << "ClapTrap constructor called for: " << RESET << name << " ";
	this->printHp(false);
	std::cout << std::endl;
}
ClapTrap::~ClapTrap( void ) {
    std::cout << C_401 << "ClapTrap Destructor called for " << name << RESET << std::endl;
}
ClapTrap::ClapTrap( const ClapTrap& other )
: name(other.name), hp(other.hp), energy(other.energy), attack_dmg(other.attack_dmg) {
    std::cout << C_041 << "ClapTrap Copy constructor called for " << name << RESET << std::endl;
}
ClapTrap& ClapTrap::operator=( const ClapTrap& other ) {
    std::cout << C_041 << "ClapTrap Copy assignment operator called for " << name << RESET << std::endl;
	name = other.name;
	hp = other.hp;
	energy = other.energy;
	attack_dmg = other.attack_dmg;
	return *this;
}

///////////////////////////////////////////////////////////////////////////////]
void ClapTrap::attack( const std::string& target ) {

	attack2(target, "\e[38;5;220mClapTrap ");
}

void ClapTrap::attack2( const std::string& target, const std::string color) {
	if (!hp || !energy) {
		this->printHp(true);
		std::cout << C_400 << "can't attack..." << RESET << std::endl;
		return;
	}
	energy--;
	this->printHp(true);
	std::cout << color << "attacks " << target << 
	", causing " << attack_dmg << " points of damage!" << RESET << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	hp -= amount;
	hp = hp < 0 ? 0 : hp;
	this->printHp(true);
	if (!amount) {
		std::cout << C_400 << " takes no damages!" << RESET << std::endl;
		return;
	}
	std::cout << C_512 << "takes " << amount << 
	" points of damage!" << RESET << std::endl;
	// std::cout << "remaining: " << hp << RESET << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (!amount) {
		this->printHp(true);
		std::cout << C_400 << "can't heal!" << RESET << std::endl;
		return;
	}
	if (!hp || !energy) {
		this->printHp(true);
		std::cout << C_400 << "is out of energy!" << RESET << std::endl;
		return;
	}
	hp += amount;
	energy--;
	this->printHp(true);
	std::cout << C_152 << "repairs itself for " << amount << " hp! " << RESET << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
void	ClapTrap::printHp( bool name ) {
	if (name)
		std::cout << this->name << " ";
	std::cout << "( " << C_151 << hp << RESET << " / " << C_015 << energy << RESET << " ) ";
}