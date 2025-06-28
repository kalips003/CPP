#include "lib/_lib.hpp"

#include <fstream>
#include <string>
#include <iostream>
#include <cstring>

int main(int ac, char** av) {

	if (ac != 4) {
		std::cerr << ERR3 "error args" << std::endl;
		return 0;
	}

	std::ifstream	file(av[1]);
	if (!file) {
		std::cerr << "Could not open the file: " << av[1] << std::endl;
		std::cerr << ERR7 << strerror(errno) << std::endl;
		return 1;
	}

	std::ostringstream ss;
	ss << file.rdbuf();
	std::string content = ss.str();

	std::string result = "";
	std::string to_find(av[2]);
	std::string to_replace_with(av[3]);
	size_t	len_to_find = to_find.length();

	size_t pos = 0;
	while ((pos = content.find(to_find, pos)) != std::string::npos) {
		result += content.substr(0, pos);
		result += to_replace_with;
		pos += len_to_find;
		content = content.substr(pos);
		pos = 0;
	}
	result += content; 

	std::ofstream	outfile((std::string(av[1]) + ".replace").c_str());
	if (!outfile) {
		std::cerr << "Error creating the file: " << av[1] << ".replace" << std::endl;
		std::cerr << ERR7 << strerror(errno) << std::endl;
		return 1;
	}
	outfile << result;
	return 0;
}