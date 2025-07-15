#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

#include "_colors.h"

class Animal {

protected:
	std::string	type;

public:
	Animal( void );
	Animal( const Animal& other );
	virtual ~Animal( void );
	Animal& operator=( const Animal& other );

	const std::string& getType( void ) const;

// GoodAnimal
	virtual void makeSound() const = 0;
	// virtual void	makeSound( void ) const;
// WrongAnimal
	// void	makeSound( void ) const;
	
};

#endif