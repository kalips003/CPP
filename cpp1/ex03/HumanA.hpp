#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

#include "_colors.h"

class HumanA {

private:
    std::string name;
    Weapon&      weapon;

public:
    HumanA( const std::string& name, Weapon& weapon);
    ~HumanA( void );

    void    attack( void );
};

#endif