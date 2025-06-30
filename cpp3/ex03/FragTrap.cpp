#include "FragTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
FragTrap::FragTrap( const std::string& name )
: ClapTrap(name) {
	ClapTrap::setStats(100, 100, 30);
	std::cout << C_135 << "FragTrap constructor called" << RESET << std::endl;
}
FragTrap::~FragTrap( void ) {
    std::cout << C_411 << "FragTrap Destructor called" << RESET << std::endl;
}
FragTrap::FragTrap( const FragTrap& other )
: ClapTrap(other) {
    std::cout << C_054 << "FragTrap Copy constructor called" << RESET << std::endl;
}
FragTrap& FragTrap::operator=( const FragTrap& other ) {
	std::cout << C_242 << "FragTrap Copy assignment operator called" << RESET << std::endl;
	ClapTrap::operator=(other);
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	FragTrap::highFivesGuys( void ) {
	std::cout << C_521 << "High Fives!" << RESET << std::endl;
}

void FragTrap::attack( const std::string& target ) {
	std::cout << C_115 << "FragTrap " << RESET;
	ClapTrap::attack(target);
}