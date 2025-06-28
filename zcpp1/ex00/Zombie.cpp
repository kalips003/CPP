#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string n ) {
	name = n;
}
Zombie::~Zombie( void ) {
	std::cout << name << ": destroyed..." << std::endl;
}

void	Zombie::announce( void ) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

