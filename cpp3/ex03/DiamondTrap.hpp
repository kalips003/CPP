#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

public:
	FragTrap( const std::string& name );
	~FragTrap( void );
	FragTrap( const FragTrap& other );
	FragTrap& operator=( const FragTrap& other );

	void highFivesGuys( void );

	void attack( const std::string& target );


};

#endif
