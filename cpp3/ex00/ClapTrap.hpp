#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#include "_colors.h"

class ClapTrap {

private:
	const std::string name;
	int			hp;
	int			energy;
	int			attack_dmg;

public:
	ClapTrap( const std::string& name );
	~ClapTrap( void );
	ClapTrap( const ClapTrap& other );
	ClapTrap& operator=( const ClapTrap& other );

	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

};

#endif