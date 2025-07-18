#include <string>
#include <iostream>
#include <fstream>

#include <cerrno>    // for errno
#include <cstring>   // for strerror

#include "_colors.h"

// ./exe path/to/file "string 1" "string 22"
int main(int ac, char** av) {

	if (ac != 4) {
		std::cout << ERR1 "wrong nuber of args, need: FILENAME, STRING1, STRING2" << std::endl;
		return 1;
	}

	std::string		s1 = av[2];
	if (s1.empty()) {
		std::cout << ERR2 "Pattern to find cant be empty" << std::endl;
		return 0;
	}

	std::string		s2 = av[3];
	std::ifstream	file(av[1]);
	if (!file) {
		std::cout << ERR3 "Cant open " << av[1] << ": " << strerror(errno) << std::endl;
		return 1;
	}

	std::string		new_file_name = std::string(av[1]) + ".replace";
	std::ofstream	out(new_file_name.c_str());

	std::string		line;
	std::size_t		pos = 0;
	std::size_t		s1_l = s1.length();
	while (std::getline(file, line)) {
		while ((pos = line.find(s1)) != std::string::npos) {
			out << line.substr(0, pos) << '\033' << "[38;5;214m" << s2 << '\033' << "[38;5;24m";
			line = line.substr(pos + s1_l);
			pos = 0;
		}
		out << line << std::endl;
	}

	return 0;
}