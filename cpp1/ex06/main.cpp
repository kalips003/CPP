#include "Harl.hpp"

static const std::string	levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

int main(int ac, char** av) {

	if (ac != 2)
		return (std::cout << "\tWRONG NUMBER OF ARGS" << std::endl, 0);
	
	Harl harl;
	std::string filter(av[1]);

	int threat_level = -1;
	for (int i = 0; i < 4; i++) {
		if (filter == levels[i]) {
			threat_level = i;
			break;
		}
	}

	switch (threat_level) {

		case 0:
			std::cout << "\t[DEBUG]" << std::endl;
			harl.complain("DEBUG");
			// fall through
		case 1:
			std::cout << "\t[INFO]" << std::endl;
			harl.complain("INFO");
			// fall through
		case 2:
			std::cout << "\t[WARNING]" << std::endl;
			harl.complain("WARNING");
			// fall through
		case 3:
			std::cout << "\t[ERROR]" << std::endl;
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return 0;
}