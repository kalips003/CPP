

#include "_colors.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

// open DB
bool	isDataBaseValid( void ) {

	std::ifstream database("data.csv");
	if (!database) {
		std::cout << ERR2 "can't locate database" RESET << std::endl;
		return false;
	}

	std::string line;
	while (getline(database, line)) {
		std::stringstream temp;
		temp << line;
	}


}





///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av)
{
	if (ac != 2) {
		std::cout << ERR0 "need one file as input" RESET << std::endl;
		return 0;
	}
// input.txt file
	// std::ifstream file(av[1]);
	// if (!file) {
	// 	std::cout << ERR1 "bad infile: " RESET << av[1] << std::endl;
	// 	return 1;
	// }

	return 0;
}