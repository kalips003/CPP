#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#include "_colors.h"

class Brain {

private:
	std::string	ideas[100];

public:
	Brain( void );
	~Brain( void );
	Brain( const Brain& other );
	Brain& operator=( const Brain& other );

	void	setIdea(int index, const std::string& idea);
	const std::string& getIdea( int index ) const;
};

#endif