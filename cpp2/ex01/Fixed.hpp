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
//--------------------------------------->
// 1 / 256 = 0.00390625
// 2^23 = -8,388,608 to 8,388,607
    Fixed( const int& i );
    Fixed( const float& f );

    float   toFloat( void ) const;
    int     toInt( void ) const;

};

std::ostream& operator<<( std::ostream& os, const Fixed& fix );



#endif