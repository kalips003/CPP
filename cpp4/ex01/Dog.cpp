#include "Dog.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Dog::Dog( void ) {
	std::cout << C_015 << "Default Dog constructor" << std::endl;
	type = "Dog";
	brain = new Brain();
}
Dog::Dog( const Dog& other ) : Animal(other) {
	std::cout << C_015 << "Dog Copy-constructor" << std::endl;
	*brain = *other.brain;
}
Dog::~Dog( void ) {
	std::cout << C_015 << "Dog destructor" << std::endl;
	delete brain;
}
Dog& Dog::operator=( const Dog& other ) {
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	Dog::makeSound( void ) const {
	std::cout << C_122 << "...Bark! Bababaaabark!" << RESET << std::endl;
}

void	Dog::hasAnIdea( int index, const std::string& new_idea ) {
	brain->setIdea(index, new_idea);
}
const std::string& Dog::TellsIdea( int index ) const {
	return brain->getIdea(index);
}
