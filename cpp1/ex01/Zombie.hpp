#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>
#include <iostream>


class Zombie {


private:
    std::string name;

public:
    void    announce( void );
    Zombie( std::string name);
    Zombie( void );
    ~Zombie( void );

    void    setName( std::string name );

};

Zombie  *newZombie( std::string name );
void    randomChump( std::string name );
Zombie  *zombieHorde( int N, std::string name );
Zombie  *zombieHorde_v2( int N, std::string name );

#endif
