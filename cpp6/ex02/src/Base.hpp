#ifndef BASE_HPP
#define BASE_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class Base {

private:

protected:

public:

/////   CANONICAL
	virtual ~Base();

};

Base *generate( void );
void	identify(Base* p);
void	identify(Base& p);

#endif
