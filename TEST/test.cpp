#include <iostream>
#include <stdio.h>
#include <sstream>

#include "MyClass.hpp"
#include "_tools.hpp"

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

template class, template argument ,  static member function??
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////]
int main() {
	std::string abc = ft_print_ccat(C_341, C_434, "abc?", 0, "Enter the first name abc", 0b110);
	std::cout << "this is abc:" + abc << std::endl;
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


