#ifndef CAT_HPP
#define CAT_HPP

#include <string>
#include <iostream>

#include "_colors.h"

#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat( void );
	~Cat( void );
	Cat( const Cat& other );
	Cat& operator=( const Cat& other );

	void	makeSound( void ) const;
};

#endif