#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon {
private:
	std::string type;
	
public:
	Weapon(std::string weapon_type);

	std::string& getType();
	void setType( std::string string);
};

#endif