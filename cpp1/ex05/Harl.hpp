#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

#include "_colors.h"

class Harl {

private:
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

public:
    void    complain( std::string level );
    Harl( void );
    ~Harl( void );
};

#endif