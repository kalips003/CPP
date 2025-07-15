#include "Cat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Cat::Cat( void ) {
	std::cout << C_420 << "Default Cat constructor" << std::endl;
	type = "Cat";
}
Cat::Cat( const Cat& other ) : Animal(other) {
	std::cout << C_420 << "Cat Copy-constructor" << std::endl;
}
Cat::~Cat( void ) {
	std::cout << C_420 << "Cat destructor" << std::endl;
}
Cat& Cat::operator=( const Cat& other ) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	Cat::makeSound( void ) const {
	std::cout << C_122 << "...mii?" << RESET << std::endl;
}