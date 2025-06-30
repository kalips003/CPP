#include "ClapTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
ClapTrap::ClapTrap( const std::string& name )
: name(name), hp(100), energy(50), attack_dmg(20) {
    std::cout << C_041 << "Default constructor called for: " << RESET << name << " ";
	this->printHp();
	std::cout << std::endl;
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
		this->printHp();
		std::cout << C_400 << name << " can't attack..." << RESET << std::endl;
		return;
	}
	energy--;
	this->printHp();
	std::cout << C_152 << "ClapTrap " << name << " attacks " << target << 
	", causing " << attack_dmg << " points of damage!" << RESET << std::endl;
}

void ClapTrap::takeDamage( unsigned int amount ) {
	hp -= amount;
	hp = hp < 0 ? 0 : hp;
	this->printHp();
	if (!amount) {
		std::cout << C_040 << "ClapTrap " << name << " takes no damages!" << RESET << std::endl;
		return;
	}
	std::cout << C_512 << "ClapTrap " << name << " takes " << amount << 
	" points of damage!" << RESET << std::endl;
	// std::cout << "remaining: " << hp << RESET << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (!amount) {
		this->printHp();
		std::cout << C_400 << "ClapTrap " << name << " can't heal!" << RESET << std::endl;
		return;
	}
	if (!hp || !energy) {
		this->printHp();
		std::cout << C_400 << name << " is out of energy!" << RESET << std::endl;
		return;
	}
	hp += amount;
	energy--;
	this->printHp();
	std::cout << C_152 << "ClapTrap " << name << " repairs itself for " << amount << 
	" hp! " << std::endl;
	// std::cout << "remaining: " << hp << RESET << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
void	ClapTrap::printHp( void ) {
	std::cout << "( " << C_151 << hp << RESET << " / " << C_015 << energy << RESET << " ) ";
}

void	ClapTrap::setStats(int hp, int energy, int attk) {
	this->hp = hp;
	this->energy = energy;
	this->attack_dmg = attk;
}
