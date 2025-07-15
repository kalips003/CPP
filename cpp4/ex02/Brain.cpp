#include "Brain.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Brain::Brain( void ) {
	std::cout << C_151 << "Default Brain constructor" << std::endl;
}
Brain::Brain( const Brain& other ) {
	std::cout << C_151 << "Brain Copy-constructor" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}
Brain::~Brain( void ) {
	std::cout << C_151 << "Brain destructor" << std::endl;
}
Brain& Brain::operator=( const Brain& other ) {
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return *this;
}
///////////////////////////////////////////////////////////////////////////////]
void	Brain::setIdea( int index, const std::string& idea ) {
	if (index >= 0 && index <= 100)
		ideas[index] = idea;
}
const std::string& Brain::getIdea( int index ) const {
	return ideas[index];
}
///////////////////////////////////////////////////////////////////////////////]