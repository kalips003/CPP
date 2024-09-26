#include "Harl.hpp"

static const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
static const int	how_many_levels = sizeof(levels) / sizeof(levels[0]);
Harl::HarlSpeachFunc Harl::speech[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

void Harl::complain( std::string level ) {

	for (int i = 0; i < how_many_levels; i++) {
		if (level == levels[i]) {
			(this->*speech[i])();
			return;
		}
	}
	std::cout << "これ、何語？マネージャーと話したいんだけど !" << std::endl;
}

void Harl::debug( void ) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!"
	<< std::endl;
}
void Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}
void Harl::warning( void ) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
	<< std::endl;
}
void Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now."
	<< std::endl;
}

