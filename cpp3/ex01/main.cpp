
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

#define SCREENX 1200
#define SCREENY 900

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main() {

	ClapTrap	A("Frank");
	ScavTrap	B("Mimi");

	std::cout << std::endl;
	A.attack("the corrector");
	B.attack("the corrector again");
	
	std::cout << std::endl;
	A.takeDamage(5);
	B.takeDamage(5);
	std::cout << std::endl;
	A.beRepaired(15);
	B.beRepaired(15);
	A.beRepaired(0);
	B.beRepaired(0);
	std::cout << std::endl;
	B.guardGate();

	std::cout << std::endl;
	ScavTrap	C("default");
	C = B;
	C.attack("the corrector");
	std::cout << std::endl;

	return 0;
}