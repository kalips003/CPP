#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() {
	name = "";
}

Zombie::Zombie( std::string n ) {
	name = n;
}

Zombie::~Zombie() {
	std::cout << name << ": destroyed..." << std::endl;
}

void	Zombie::announce() {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}


