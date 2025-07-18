#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>

#include "_colors.h"

class Zombie {

private:
    std::string name;

public:
    void    announce( void );
    Zombie( std::string name);
    ~Zombie( void );

};

Zombie  *newZombie(std::string name);
void    randomChump( std::string name );

#endif
