#ifndef DEFAULT_HPP
#define DEFAULT_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class Default {

private:

protected:

public:

/////   CANONICAL
	Default();
	Default(const Default &other);
	Default& operator=(const Default& other);
	~Default();

/////   SETTER GETTER
	void setAttribute(int value);
	int getAttribute() const;

};

#endif

