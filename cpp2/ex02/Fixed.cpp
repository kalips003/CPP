#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;
///////////////////////////////////////////////////////////////////////////////]
// CANONICAL FORM
Fixed::Fixed( void ) 
: num(0) {
    // std::cout << C_041 << "Default constructor called" << RESET << std::endl;
}
Fixed::~Fixed( void ) {
    // std::cout << C_401 << "Destructor called" << RESET << std::endl;
}
// Fixed::Fixed( const Fixed& other ) {
//     this->num = other.getRawBits();
//     std::cout << C_042 << "Copy constructor called" << std::endl;
// }
Fixed::Fixed( const Fixed& other ) 
: num(other.num) {
    // std::cout << C_042 << "Copy constructor called" << RESET << std::endl;
}
Fixed& Fixed::operator=( const Fixed& other ) {
    if (this != &other)
        this->num = other.num;
    // std::cout << C_141 << "Copy assignment operator called" << RESET << std::endl;
    return *this;
}

///////////////////////////////////////////////////////////////////////////////]
int     Fixed::getRawBits( void ) const {
    // std::cout << C_241 << "getRawBits member function called" << RESET << std::endl;
    return this->num;
}
void    Fixed::setRawBits( int const raw ) {
    this->num = raw;
}

///////////////////////////////////////////////////////////////////////////////]
// 1 / 256 = 0.00390625
// 2^23 = -8,388,608 to 8,388,607
Fixed::Fixed( const int& i ) {
    // std::cout << C_114 << "Int constructor called" << RESET << std::endl;
    if (i < -8388607 || i > 8388608)
        std::cout << RED << "Carefull, values will be overflow garbage: ("
        C_431 << i << RED << ")" << RESET << std::endl;
    num = i * 256; 
}
Fixed::Fixed( const float& f ) {
    // std::cout << C_314 << "Float constructor called" << RESET << std::endl;
    num = static_cast<int>(f  * 256);
}

float   Fixed::toFloat( void ) const {
    return static_cast<float>(num) / 256;
    return roundf(num / 256);
}
int     Fixed::toInt( void ) const {
    return static_cast<int>(roundf(num / 256.0f));
    return num / 256;
}

std::ostream& operator<<( std::ostream& os, const Fixed& fix ) {
    os << fix.toFloat();
    return os;
}

///////////////////////////////////////////////////////////////////////////////]
bool    Fixed::operator<(const Fixed& a) const {
    return num < a.num;
}
bool    Fixed::operator>(const Fixed& a) const {
    return num > a.num;
}
bool    Fixed::operator<=(const Fixed& a) const {
    return num <= a.num;
}
bool    Fixed::operator>=(const Fixed& a) const {
    return num >= a.num;
}
bool    Fixed::operator==(const Fixed& a) const {
    return num == a.num;
}
bool    Fixed::operator!=(const Fixed& a) const {
    return num != a.num;
}
///////////////////////////////////////////////////////////////////////////////]
Fixed    Fixed::operator+(const Fixed& a) {
    Fixed rtrn;
    rtrn.num = a.num + num;
    return rtrn;
}
Fixed    Fixed::operator-(const Fixed& a) {
    Fixed rtrn;
    rtrn.num = num - a.num;
    return rtrn;
}
Fixed    Fixed::operator*(const Fixed& a) {
    Fixed rtrn;
    rtrn.num = static_cast<long long>(num) * a.num / 256;
    return rtrn;
}
Fixed    Fixed::operator/(const Fixed& a) {
    Fixed rtrn;
    if (a.num == 0)
        std::cout << RED << "Division by Zero, returning zero" << RESET << std::endl;
    else
        rtrn.num = static_cast<long long>(num) * 256 / a.num;
    return rtrn;
}
///////////////////////////////////////////////////////////////////////////////]
//  ++a
Fixed&    Fixed::operator++() {
    num += 1;
    return *this;
}
Fixed&    Fixed::operator--() {
    num -= 1;
    return *this;
}
//  a++
Fixed    Fixed::operator++(int) {
    Fixed temp(*this);
    num += 1;
    return temp;
}
Fixed    Fixed::operator--(int) {
    Fixed temp(*this);
    num -= 1;
    return temp;
}
///////////////////////////////////////////////////////////////////////////////]
Fixed&  Fixed::min( Fixed& a, Fixed&b ) {
    return a.num <= b.num ? a : b;
}
Fixed&  Fixed::max( Fixed& a, Fixed&b ) {
    return a.num >= b.num ? a : b;
}
const Fixed&  Fixed::min( const Fixed& a, const Fixed& b ) {
    return a.num <= b.num ? a : b;
}
const Fixed&  Fixed::max( const Fixed& a, const Fixed& b ) {
    return a.num >= b.num ? a : b;
}