#include <iostream>
#include <stdio.h>

#include "MyClass.hpp"

/*******************************************************************************
******************************************************************************/
// <!> - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  </!>
///////////////////////////////////////////////////////////////////////////////]
/*******************************************************************************

			░█████╗░  ███████╗░█████╗░██╗██████╗░███████╗
			██╔══██╗  ██╔════╝██╔══██╗██║██╔══██╗██╔════╝
			███████║  █████╗░░███████║██║██████╔╝█████╗░░
			██╔══██║  ██╔══╝░░██╔══██║██║██╔══██╗██╔══╝░░
			██║░░██║  ██║░░░░░██║░░██║██║██║░░██║███████╗
			╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝╚══════╝
******************************************************************************/
# define CLEAR "\e[2J\e[H"
# define RESET "\e[0m"
# define BLINK "\e[5m"
# define R_BLINK "\e[25m"
void	ft_print_cat(int num, std::string string2, int bit)
{
	srand(time(NULL));
	std::string color1 = "\e[38;5;" + std::to_string((rand() % 255 + 1)) + "m";
	std::string color2 = "\e[38;5;" + std::to_string((rand() % 255 + 1)) + "m";
	std::string color3 = "\e[38;5;" + std::to_string((rand() % 255 + 1)) + "m";
	if ((bit >> 1) & 1)
		std::cout << CLEAR;
	std::cout << color2 << "\t\tにゃ~" << color1 << "\t⠀╱|、\n\
	\t\t(˚ˎ。7⠀⠀⠀" << color2 << "~ " << num << " ~" + color1 + "\n\
	\t\t⠀|、˜\\\t\t\t" + color2 + "~" + string2 + "~" + color1 + "\n\
	\t\t⠀じしˍ)ノ\n" << std::endl;
	if ((bit >> 0) & 1)
	{
		std::cout << BLINK + color3 + "\n\t\t>>>  PRISS ENTER TO CONTINUE  <<<\n" + R_BLINK;
		std::getline(std::cin, color1);
	}
}

///////////////////////////////////////////////////////////////////////////////]
int main() {
	ft_print_cat(0, "hello", 0b11);
	ft_print_cat(1, "hello", 0b11);
	ft_print_cat(2, "hello", 0b11);
    return 0;
}
///////////////////////////////////////////////////////////////////////////////]


/*******************************************************************************
// User-Defined Types

struct Point {
    int x;
    int y;
};

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
};

enum Color {
    RED,
    GREEN,
    BLUE
};

union Data {
    int intValue;
    float floatValue;
    char charValue;
};

// Standard Library Types

#include <vector>
std::vector<int> numbers;  // Dynamic array

#include <list>
std::list<int> myList;     // Doubly linked list

#include <map>
std::map<std::string, int> ages;  // Key-value pairs

#include <utility>
std::pair<int, std::string> person;  // Pair of two types

#include <string>
std::string name;  // String type

******************************************************************************/


