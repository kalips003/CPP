#include "ScavTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
ScavTrap::ScavTrap( const std::string& name )
: ClapTrap(name) {
    std::cout << C_135 << "ScavTrap constructor called" << RESET << std::endl;
}
ScavTrap::~ScavTrap( void ) {
    std::cout << C_411 << "ScavTrap Destructor called" << RESET << std::endl;
}
ScavTrap::ScavTrap( const ScavTrap& other )
: ClapTrap(other) {
    std::cout << C_054 << "ScavTrap Copy constructor called" << RESET << std::endl;
}
ScavTrap& ScavTrap::operator=( const ScavTrap& other ) {
	std::cout << C_242 << "ScavTrap Copy assignment operator called" << RESET << std::endl;
	ClapTrap::operator=(other);
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	guardGate( void ) {
	std::cout << C_521 << "ScavTrap is now in Gatekeeper mode" << RESET << std::endl;
}

void ScavTrap::attack( const std::string& target ) {
	std::cout << C_115 << "ScavTrap " << RESET;
	ClapTrap::attack(target);
}