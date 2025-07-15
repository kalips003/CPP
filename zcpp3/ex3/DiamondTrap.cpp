#include "DiamondTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
DiamondTrap::DiamondTrap( const std::string& name )
: ClapTrap(name) {
	ClapTrap::setStats(100, 100, 30);
	std::cout << C_135 << "DiamondTrap constructor called" << RESET << std::endl;
}
DiamondTrap::~DiamondTrap( void ) {
    std::cout << C_411 << "DiamondTrap Destructor called" << RESET << std::endl;
}
DiamondTrap::DiamondTrap( const DiamondTrap& other )
: ClapTrap(other) {
    std::cout << C_054 << "DiamondTrap Copy constructor called" << RESET << std::endl;
}
DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other ) {
	std::cout << C_242 << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
	ClapTrap::operator=(other);
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	DiamondTrap::whoAmI( void ) {
	std::cout << C_521 << "High Fives!" << RESET << std::endl;
}

void DiamondTrap::attack( const std::string& target ) {
	std::cout << C_115 << "DiamondTrap " << RESET;
	ClapTrap::attack(target);
}