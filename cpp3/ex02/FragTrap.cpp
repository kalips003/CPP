#include "FragTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
FragTrap::FragTrap( const std::string& name )
: ClapTrap(name) {
	setStats(100, 100, 30);
    std::cout << C_151 << "FragTrap constructor called for " << name << RESET << std::endl;
}
FragTrap::~FragTrap( void ) {
    std::cout << C_411 << "FragTrap Destructor called" << RESET << std::endl;
}
FragTrap::FragTrap( const FragTrap& other )
: ClapTrap(other) {
    std::cout << C_151 << "FragTrap Copy constructor called" << RESET << std::endl;
}
FragTrap& FragTrap::operator=( const FragTrap& other ) {
	std::cout << C_151 << "FragTrap Copy assignment operator called" << RESET << std::endl;
	ClapTrap::operator=(other);
	return *this;
}

///////////////////////////////////////////////////////////////////////////////]
void	FragTrap::highFivesGuys( void ) {
	this->printHp(true);
	std::cout << " High Fives!" << RESET << std::endl;
}

void FragTrap::attack( const std::string& target ) {

	ClapTrap::attack2(target, "\e[38;5;63mFragTrap ");
}