
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main() {

	ClapTrap	A("Frank");
	ScavTrap	B("Mimi");
	FragTrap	D("Francine");

	std::cout << std::endl;
	A.attack("the corrector");
	B.attack("the corrector");
	D.attack("the corrector");
	
	std::cout << std::endl;
	A.takeDamage(5);
	B.takeDamage(5);
	D.takeDamage(5);
	std::cout << std::endl;
	A.beRepaired(15);
	B.beRepaired(15);
	D.beRepaired(15);
	A.beRepaired(0);
	B.beRepaired(0);
	D.beRepaired(0);
	std::cout << std::endl;
	B.guardGate();
	D.highFivesGuys();

	std::cout << std::endl;
	FragTrap	C("default");
	C = D;
	C.attack("YOU again!");
	std::cout << std::endl;

	return 0;
}