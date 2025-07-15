#include "Animal.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Animal::Animal( void ) : type("blank") {
	std::cout << C_431 << "Default Animal constructor" << RESET << std::endl;
}
Animal::Animal( const Animal& other ) : type(other.type) {
	std::cout << C_431 << "Animal Copy-constructor" << RESET << std::endl;
}
Animal::~Animal( void ) {
	std::cout << C_431 << "Animal destructor" << RESET << std::endl;
}
Animal& Animal::operator=( const Animal& other ) {
	if (this != &other)
		type = other.type;
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
const std::string& Animal::getType( void ) const {
	return type;
}

///////////////////////////////////////////////////////////////////////////////]
void	Animal::makeSound( void ) const {
	std::cout << C_111 << "..." << RESET << std::endl;
}

