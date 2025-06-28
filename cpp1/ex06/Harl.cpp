#include "Harl.hpp"

const std::string Harl::levels[4] = {
    "DEBUG", "INFO", "WARNING", "ERROR"
};
void (Harl::*const Harl::ft_lvl[4])() = {
    &Harl::debug, &Harl::info, &Harl::warning, &Harl::error
};

///////////////////////////////////////////////////////////////////////////////]
void    Harl::debug( void ) {
    std::cout << std::string(C_120) + "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- \
ketchup burger. I really do!" << std::endl;
}
void    Harl::info( void ) {
    std::cout << std::string(C_320) + "I cannot believe adding extra bacon costs more money. You didn’t put \
enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void    Harl::warning( void ) {
    std::cout << std::string(C_410) + "I think I deserve to have some extra bacon for free. I’ve been coming for \
years whereas you started working here since last month." << std::endl;
}
void    Harl::error( void ) {
    std::cout << std::string(C_500) + "This is unacceptable! I want to speak to the manager now." << std::endl;
}
///////////////////////////////////////////////////////////////////////////////]

void    Harl::complain( std::string level ) {

    int lvl = this->whatLevel(level);
    if (lvl == 4)
        std::cout << std::string(C_213) + "[ Probably complaining about insignificant problems ]" << std::endl;
    else
        (this->*ft_lvl[lvl])();
    std::cout << RESET;
}

int     Harl::whatLevel( std::string level ) {
    int i = 0;
    for (; i < 4; i++) {
        if (level == levels[i])
            break ;
    }
    return i;
}

///////////////////////////////////////////////////////////////////////////////]
Harl::Harl( void ) {}

Harl::~Harl( void ) {}