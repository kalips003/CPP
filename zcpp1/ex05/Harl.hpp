#ifndef HARL_HPP
#define HARL_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>


class Harl {

typedef void (Harl::*HarlSpeachFunc)();
static Harl::HarlSpeachFunc	speech[];

private:
	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	void complain( std::string level );
};

#endif

