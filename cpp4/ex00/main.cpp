
#include "Dog.hpp"
#include "Cat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
// int main() {

// 	Animal	a;
// 	Cat 	cat;
// 	Dog		dog;

// 	a.makeSound();
// 	cat.makeSound();
// 	dog.makeSound();

// 	return 0;
// }

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;
	std::cout << C_145 "Type of dog?: " RESET << j->getType() << " " << std::endl;
	std::cout << C_145 "Type of cat?: " RESET << i->getType() << " " << std::endl;
	std::cout << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	
	std::cout << std::endl;
	delete meta;
	delete j;
	delete i;
	return 0;
}