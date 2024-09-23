# ifndef TOOLS_HPP
# define TOOLS_HPP

#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <string>
#include <sstream>
// #include <cctype>

#include "_colors.h"

std::string	ft_print_ccat(std::string color1, std::string color2, std::string color3, int num, std::string string, int bit);
void	ft_print_cat(int num, std::string string2, int bit);

#endif