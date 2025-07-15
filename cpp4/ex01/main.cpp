
#include "Brain.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
#define	SPA 10
///////////////////////////////////////////////////////////////////////////////]
int main() {

	Animal	*ar[SPA];

	for (int i = 0; i < SPA; i++) {
		if (i % 2)
			ar[i] = new Cat();
		else
			ar[i] = new Dog();
		std::cout << ar[i]->getType() << std::endl;
		ar[i]->makeSound();
	}

	std::cout << C_012 << "------------" << RESET << std::endl;
	Dog *dog_a = dynamic_cast<Dog*>(ar[0]);
	Dog *dog_b = dynamic_cast<Dog*>(ar[2]);
	dog_a->hasAnIdea(0, "i like cheese");
	*dog_b = *dog_a;
	std::cout << C_413 << "dog 2 ideas are: " << RESET << dog_b->TellsIdea(0) << std::endl;
	std::cout << C_012 << "------------" << RESET << std::endl;

	for (int i = 0; i < SPA; i++)
		delete ar[i];

	return 0;
}

// int main()
// {
// 	const Animal* j = new Dog();
// 	const Animal* i = new Cat();
// 	delete j;//should not create a leak
// 	delete i;

// 	return 0;
// }