#include "Zombie.hpp"

///////////////////////////////////////////////////////////////////////////////]

Zombie::Zombie( std::string name )
: name(name) {
}
Zombie::~Zombie( void ) {
    std::cout << name << ": Deeaaad..." << std::endl;
}
Zombie::Zombie( void ) 
: name("empty") {   
}
///////////////////////////////////////////////////////////////////////////////]
void   Zombie::announce( void ) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie  *newZombie(std::string name) {

    return new Zombie(name);
}

void    randomChump( std::string name ) {

    Zombie  frank(name);
    frank.announce();
}

void    Zombie::setName( std::string name ) {
    this->name = name;
}