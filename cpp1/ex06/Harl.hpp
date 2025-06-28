#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>
#include "_colors.h"

class Harl {

private:
    static void (Harl::*const ft_lvl[4])();
    void    debug( void );
    void    info( void );
    void    warning( void );
    void    error( void );

public:
    static const std::string levels[4];
    void    complain( std::string level );
    int     whatLevel( std::string level );
    Harl( void );
    ~Harl( void );
};

#endif
