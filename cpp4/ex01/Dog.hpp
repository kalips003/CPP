#ifndef DOG_HPP
#define DOG_HPP

#include <string>
#include <iostream>

#include "_colors.h"

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

private:
	Brain *brain;

public:
	Dog( void );
	~Dog( void );
	Dog( const Dog& other );
	Dog& operator=( const Dog& other );

	void	makeSound( void ) const;
	void	hasAnIdea( int index, const std::string& new_idea );
	const std::string&	TellsIdea( int index ) const;
};

#endif