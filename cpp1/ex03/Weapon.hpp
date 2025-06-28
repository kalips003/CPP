#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {

private:
    std::string type;

public:
    const std::string&  getType( void ) const;
    void                setType( const std::string &new_type );

    Weapon( const std::string& type );
    ~Weapon( void );

};

#endif
