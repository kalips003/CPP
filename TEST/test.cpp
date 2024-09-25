#include "lib/_lib.hpp"

#include <iostream>
// std::cin; std::cout; std::cerr; std::endl
#include <string>
// std::string
// #include <vector>
// std::vector (not allowed until Module 08)
// #include <map>
// std::map (not allowed until Module 08)
// #include <set>
// std::set (not allowed until Module 08)
// #include <algorithm>
// std::sort; std::find; std::for_each (not allowed until Module 08)
// #include <cstdlib>
// std::malloc; std::free; std::rand; std::exit
// #include <cmath>
// std::abs; std::sqrt; std::pow
// #include <ctime>
// std::time; std::clock
// #include <iomanip>
// std::setprecision; std::fixed
// #include <sstream> //	string stream
// std::stringstream; std::istringstream; std::ostringstream
// #include <utility>
// std::pair; std::make_pair
// #include <cassert>
// std::assert
// #include <cctype>
// std::isdigit(int c); std::toupper(int c)
// #include <cstdlib>
// for rand() and srand()

// <!> - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  </!>
///////////////////////////////////////////////////////////////////////////////]
/*******************************************************************************
┌───┬───┐
│   │   │
├───┼───┤
│   │   │
└───┴───┘

template class, template argument ,  static member function??
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////]
#include <fstream>
#include <cstring>

///////////////////////////////////////////////////////////////////////////////]
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
	} else {
		std::ostringstream ss;
		ss << file.rdbuf();
		std::string content = ss.str();
	}



	std::ofstream	outfile(av[1] + ".replace");

	return 0;
}
///////////////////////////////////////////////////////////////////////////////]


/*******************************************************************************

std::string:

    size() / length()
		Returns the number of characters.
    empty()
		Checks if the string is empty.
    clear()
		Clears the string (makes it empty).
    at(size_type pos)
		Accesses the character at a specific position (with bounds checking).
    operator[]
		Accesses a character at a specific position (without bounds checking).
    append(const std::string&)
		Appends another string.
    substr(size_type pos, size_type len)
		Returns a substring.
    find(const std::string&)
		Finds the first occurrence of a substring.
    compare(const std::string&)
		Compares two strings.
    c_str()
		Returns a C-style string (const char*).
    replace(size_type pos, size_type len, const std::string&)
		Replaces part of the string with another.
    insert(size_type pos, const std::string&)
		Inserts another string at a position.
    erase(size_type pos, size_type len)
		Erases part of the string.
    push_back(char)
		Appends a character.
    pop_back()
		Removes the last character.
    resize(size_type newSize)
		Resizes the string to a new size.
    swap(std::string&)
		Swaps the contents of two strings.

std::getline(std::istream& input, std::string& str);










template <typename T>
T add(T a, T b) {
    return a + b;
}


template <typename T>
class Box {
public:
    T value; // value can be of any type T
    Box(T v) : value(v) {}
};






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


/*******************************************************************************
struct Base {};
struct Derived : Base {};  // public inheritance

class BaseClass {};
class DerivedClass : BaseClass {};  // private inheritance



extern "C" {
    struct Data {
        int id;
        char name[20];
    };
}


truct Point {
    int x, y;
    
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
    ~Point() {}
};

Member Functions:

cpp

struct Point {
    int x, y;
    
    void print() const {
        std::cout << "Point(" << x << ", " << y << ")" << std::endl;
    }
};

Operator Overloading:

cpp

struct Point {
    int x, y;
    
    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
};

Inheritance and Polymorphism:

cpp

    struct Base {
        virtual void speak() { std::cout << "Base speaking" << std::endl; }
    };

    struct Derived : Base {
        void speak() override { std::cout << "Derived speaking" << std::endl; }
    };

5. Use Cases for struct:

    Data Storage: structs are useful when you need to represent simple, passive data structures like coordinates, RGB values, or database records.

    Example:

    cpp

struct RGB {
    int red, green, blue;
};
******************************************************************************/