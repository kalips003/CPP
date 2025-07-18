#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;
///////////////////////////////////////////////////////////////////////////////]
// CANONICAL FORM
Fixed::Fixed( void ) 
: num(0) {
    std::cout << C_041 << "Default constructor called" << std::endl;
}
Fixed::~Fixed( void ) {
    std::cout << C_401 << "Destructor called" << std::endl;
}
// Fixed::Fixed( const Fixed& other ) {
//     this->num = other.getRawBits();
//     std::cout << C_042 << "Copy constructor called" << std::endl;
// }
Fixed::Fixed( const Fixed& other ) 
: num(other.num) {
    std::cout << C_032 << "Copy constructor called" << std::endl;
}
Fixed& Fixed::operator=( const Fixed& other ) {
    if (this != &other)
        this->num = other.num;
    std::cout << C_252 << "Copy assignment operator called" << std::endl;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////]
int     Fixed::getRawBits( void ) const {
    std::cout << C_124 << "getRawBits member function called" << std::endl;
    return this->num;
}
void    Fixed::setRawBits( int const raw ) {
    this->num = raw;
}

