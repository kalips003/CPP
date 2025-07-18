#include "Zombie.hpp"


///////////////////////////////////////////////////////////////////////////////]
Zombie::Zombie( std::string name)
: name(name) {
}
Zombie::~Zombie( void ) {
    std::cout << name << ":" << C_312 " Deeaaad..." RESET << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
void   Zombie::announce( void ) {
    std::cout << name << ":" << C_414 " BraiiiiiiinnnzzzZ..." RESET << std::endl;
}

Zombie  *newZombie(std::string name) {

    return new Zombie(name);
}

void    randomChump( std::string name ) {

    Zombie(name).announce();
}