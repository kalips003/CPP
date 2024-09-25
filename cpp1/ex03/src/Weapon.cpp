#include "Weapon.hpp"

std::string& Weapon::getType() {
	return type;
}
void         Weapon::setType(std::string s) {
	type = s;
}