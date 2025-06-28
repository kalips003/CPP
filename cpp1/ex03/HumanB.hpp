#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {

private:
    std::string name;
    Weapon*     weapon;

public:
    HumanB( const std::string& name);
    ~HumanB( void );

    void    attack( void );
    void    setWeapon( Weapon& new_weapon );
};
















#endif