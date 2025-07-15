#include "Dog.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Dog::Dog( void ) {
	std::cout << C_015 << "Default Dog constructor" << std::endl;
	type = "Dog";
}
Dog::Dog( const Dog& other ) : Animal(other) {
	std::cout << C_015 << "Dog Copy-constructor" << std::endl;
}
Dog::~Dog( void ) {
	std::cout << C_015 << "Dog destructor" << std::endl;
}
Dog& Dog::operator=( const Dog& other ) {
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	Dog::makeSound( void ) const {
	std::cout << C_122 << "...Bark! Bababaaabark!" << RESET << std::endl;
}