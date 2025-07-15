#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>
#include <iostream>

#include "_colors.h"

class ClapTrap {

private:
	std::string name;
	int			hp;
	int			energy;
	int			attack_dmg;

public:
	ClapTrap( void );
	ClapTrap( const std::string& name );
	~ClapTrap( void );
	ClapTrap( const ClapTrap& other );
	ClapTrap& operator=( const ClapTrap& other );

	virtual void attack( const std::string& target );
	virtual void attack2( const std::string& target, const std::string color );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	void printHp( bool name );
	void setStats(int hp, int energy, int attk);
	void setName( const std::string& name );
	std::string &getName( void );
};

#endif