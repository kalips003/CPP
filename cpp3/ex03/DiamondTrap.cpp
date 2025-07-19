#include "DiamondTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
DiamondTrap::DiamondTrap( const std::string& name )
: ClapTrap(name + "_clap_name"), ScavTrap(), FragTrap(), name(name) {
	ClapTrap::setStats(100, 100, 30);
	std::cout << C_135 << "DiamondTrap constructor called" << RESET << std::endl;
	std::string a = ClapTrap::getName();
	std::cout << RED << "ClapTrap::getName  " << RESET << a << std::endl;

}
DiamondTrap::DiamondTrap( const DiamondTrap& other )
: ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name) {
	ClapTrap::setName(name + "_clap_name");
    std::cout << C_054 << "DiamondTrap Copy constructor called" << RESET << std::endl;
}
DiamondTrap::~DiamondTrap( void ) {
    std::cout << C_405 << "DiamondTrap Destructor called" << RESET << std::endl;
}
///////////////////////////////////////////////////////////////////////////////]
DiamondTrap& DiamondTrap::operator=( const DiamondTrap& other ) {
	std::cout << C_242 << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
	ClapTrap::operator=(other);
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
void	DiamondTrap::whoAmI( void ) {
	std::cout << "Who am I?! I AM " << C_521 << name << RESET << " the " << C_521 << getName() << RESET << "!" << std::endl;
}

void DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}