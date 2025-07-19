
#include "ClapTrap.hpp"

#define SCREENX 1200
#define SCREENY 900

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main() {

	ClapTrap	A("Frank");

	std::cout << std::endl;
	A.attack("the corrector!");
	A.takeDamage(5);
	A.takeDamage(0);
	A.takeDamage(4);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(2);
	A.beRepaired(3);
	A.beRepaired(1);
	std::cout << std::endl;

	ClapTrap	B("Lala");
	std::cout << std::endl;
	B.takeDamage(5);
	B.takeDamage(4);
	B.takeDamage(4);
	B.takeDamage(4);

	std::cout << std::endl;
	return 0;
}