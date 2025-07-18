#include "Harl.hpp"

int main() {

	Harl harl;

	std::cout << C_151 "\t[DEBUG]" RESET << std::endl;
	harl.complain("DEBUG");
	std::cout << C_241 "\t[INFO]" RESET << std::endl;
	harl.complain("INFO");
	std::cout << C_331 "\t[WARNING]" RESET << std::endl;
	harl.complain("WARNING");
	std::cout << C_421 "\t[ERROR]" RESET << std::endl;
	harl.complain("ERROR");
	std::cout << C_511 "\t[UNKNOWN]" RESET << std::endl;
	harl.complain("UNKNOWN");
	return 0;
}