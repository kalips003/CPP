#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon&		weapon;

public:

///////////////////////////////////////////////////////////////////////////////]
	HumanA(const std::string& n, Weapon& w);

	void attack();
};

#endif