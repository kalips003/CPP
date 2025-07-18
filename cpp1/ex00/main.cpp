#include "Zombie.hpp"

int	main() { 

	std::cout << "What would you like to name your pet zombie?" << std::endl;

	std::string input;
	if (!std::getline(std::cin, input))
		return 0;
	
	std::string name = std::string(C_513) + input + std::string(RESET);
	Zombie *frank = newZombie(name);

	name = std::string(C_451) + input + std::string("sette") + std::string(RESET);
	Zombie	francoise(name);

	frank->announce();
	francoise.announce();
	name = std::string(C_541) + std::string("Sir. ") + input + std::string(RESET);
	randomChump(name);
	delete frank;
	return 0;
}