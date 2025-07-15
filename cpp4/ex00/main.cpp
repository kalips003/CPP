
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

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	
	delete meta;
	delete j;
	delete i;
	return 0;
}