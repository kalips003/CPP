
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main() {

	ClapTrap	A("Frank");
	ScavTrap	B("Mimi");
	FragTrap	C("Lulu");
	DiamondTrap	D("Francine");

	std::cout << std::endl;
	A.attack("the corrector");
	B.attack("the corrector");
	C.attack("the corrector");
	D.attack("the corrector");
	
	std::cout << std::endl;
	A.takeDamage(5);
	B.takeDamage(5);
	C.takeDamage(5);
	D.takeDamage(5);
	std::cout << std::endl;
	A.beRepaired(15);
	B.beRepaired(15);
	C.beRepaired(15);
	D.beRepaired(15);
	A.beRepaired(0);
	B.beRepaired(0);
	C.beRepaired(0);
	D.beRepaired(0);
	// D.beRepaired(0);
	std::cout << std::endl;
	B.guardGate();
	D.guardGate();
	C.highFivesGuys();
	D.highFivesGuys();
	D.whoAmI();
	std::cout << std::endl;

	return 0;
}