#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB( const std::string& name)
: name(name), weapon(NULL)  
{}
HumanB::~HumanB( void ) {}

void    HumanB::attack( void ) { 
    std::cout << name << " attacks with their: " 
        << (weapon ? weapon->getType() : C_211 "bare hands!" RESET) << std::endl;
}

void    HumanB::setWeapon( Weapon& new_weapon ) {
    weapon = &new_weapon;
}