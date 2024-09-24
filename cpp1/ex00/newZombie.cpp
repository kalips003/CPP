#include "Zombie.hpp"

Zombie* newZombie( std::string name ) {
	Zombie* charles = new Zombie(name);
	return charles;
}