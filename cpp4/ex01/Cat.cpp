#include "Cat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Cat::Cat( void ) {
	std::cout << C_420 << "Default Cat constructor" << std::endl;
	type = "Cat";
	brain = new Brain();
}
Cat::Cat( const Cat& other ) : Animal(other) {
	std::cout << C_420 << "Cat Copy-constructor" << std::endl;
	*brain = *other.brain;
}
Cat::~Cat( void ) {
	std::cout << C_420 << "Cat destructor" << std::endl;
	delete brain;
}
Cat& Cat::operator=( const Cat& other ) {
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	Cat::makeSound( void ) const {
	std::cout << C_122 << "...mii?" << RESET << std::endl;
}