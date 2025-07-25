#include "ScavTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
ScavTrap::ScavTrap( const std::string& name )
: ClapTrap(name) {
    std::cout << C_135 << "ScavTrap constructor called for " << name << RESET << std::endl;
}
ScavTrap::~ScavTrap( void ) {
    std::cout << C_411 << "ScavTrap Destructor called" << RESET << std::endl;
}
ScavTrap::ScavTrap( const ScavTrap& other )
: ClapTrap(other) {
    std::cout << C_135 << "ScavTrap Copy constructor called" << RESET << std::endl;
}
ScavTrap& ScavTrap::operator=( const ScavTrap& other ) {
	std::cout << C_135 << "ScavTrap Copy assignment operator called" << RESET << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

///////////////////////////////////////////////////////////////////////////////]
void	ScavTrap::guardGate( void ) {
	this->printHp(true);
	std::cout << " is now in Gatekeeper mode" << RESET << std::endl;
}

void ScavTrap::attack( const std::string& target ) {

	ClapTrap::attack2(target, "\e[38;5;63mScavTrap ");
}