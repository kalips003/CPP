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
///////////////////////////////////////////////////////////////////////////////]
int main() {
	MyClass obj;  // Create an instance of MyClass
    obj.setAttribute(5);  // Set the attribute value
    int value = obj.getAttribute();  // Get the attribute value
    std::cout << "Hello, World! = " << value << std::endl;
    std::cout << "NAME = " << obj.name << std::endl;
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


