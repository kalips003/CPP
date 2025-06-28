#include "Zombie.hpp"
#include <iostream>
// #include <iomanip>

int	main() { 
	std::string input = "frank";
	std::cout << "what would you like to name your pet zombie?" << std::endl;
	if (!std::getline(std::cin, input))
		return 0;
	
	Zombie *frank = newZombie(input);
	Zombie	francoise(input + std::string("sette"));

	frank->announce();
	francoise.announce();
	delete frank;
	return 0;
}