#include "Harl.hpp"

int main(int ac, char **av) {

	if (ac != 2) {
		std::cout << "harlFilter takes one complain level as argument" << std::endl;
		return 0;
	}

	Harl harl;
	int	 lvl = harl.whatLevel(std::string(av[1]));

	if (lvl < 4)
		std::cout << "[ " << av[1] << " ]" << std::endl << std::endl;
	
	switch(lvl) {
		case 0:
			harl.complain(Harl::levels[0]);
		// fall through
		case 1:
			harl.complain(Harl::levels[1]);
		// fall through
		case 2:
			harl.complain(Harl::levels[2]);
		// fall through
		case 3:
			harl.complain(Harl::levels[3]);
			break;
		default:
			harl.complain("complaining...");
	}
	return 0;
}