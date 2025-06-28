#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include "_colors.h"

class Fixed {

private:
    int num;
    static const int    fractional_bits;


public:
    Fixed( void );
    ~Fixed( void );
    Fixed( const Fixed& other );
    Fixed& operator=( const Fixed& other );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw );

};




#endif