#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type) : type(weapon_type) {}

std::string& Weapon::getType() {
	return type;
}
void Weapon::setType(std::string s) {
	type = s;
}