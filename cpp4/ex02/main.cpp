
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
#define	SPA 10
///////////////////////////////////////////////////////////////////////////////]
int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	

	std::cout << std::endl;
	std::cout << C_145 "Type of dog?: " RESET << j->getType() << " " << std::endl;
	std::cout << C_145 "Type of cat?: " RESET << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	
	std::cout << std::endl;
	delete j;
	delete i;
	return 0;
}