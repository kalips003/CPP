#include "Harl.hpp"

int main() {

	Harl harl;

	std::cout << "\t[DEBUG]" << std::endl;
	harl.complain("DEBUG");
	std::cout << "\t[INFO]" << std::endl;
	harl.complain("INFO");
	std::cout << "\t[WARNING]" << std::endl;
	harl.complain("WARNING");
	std::cout << "\t[ERROR]" << std::endl;
	harl.complain("ERROR");
	std::cout << "\t[UNKNOWN]" << std::endl;
	harl.complain("UNKNOWN");
	return 0;
}