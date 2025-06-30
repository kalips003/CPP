
#include "ClapTrap.hpp"

#define SCREENX 1200
#define SCREENY 900

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main() {

	ClapTrap	A("Frank");

	A.attack("the corrector");
	A.takeDamage(5);
	A.takeDamage(0);
	A.takeDamage(25);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);
	A.beRepaired(1);

	return 0;
}