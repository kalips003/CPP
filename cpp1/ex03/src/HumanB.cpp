#include "HumanB.hpp"

HumanB::HumanB(const std::string& n) : name(n), weapon(NULL) {}

void HumanB::attack() {
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
	};
void HumanB::setWeapon(Weapon& w) { weapon = &w; }
