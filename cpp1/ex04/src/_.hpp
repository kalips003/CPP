#ifndef DEFAULT_HPP
#define DEFAULT_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
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

#include <cstdlib>
// for rand() and srand()

///////////////////////////////////////////////////////////////////////////////]
// bibi lib
#include "_lib.hpp"

///////////////////////////////////////////////////////////////////////////////]
// STRUCTS

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class Default {
/////   PRIVATE DATA
private:
	int attribute;
/////   PUBLIC DATA
public:
	std::string label;

/////   FONCTIONS D'USAGE
public:
	Default();
	Default(int i, const std::string &s) : attribute(i), label(s) {}
	Default(const Default &other);
	Default& operator+(const Default &other) {};
	~Default();

/////   PUBLIC SETTER GETTER
	void setAttribute(int value);
	int getAttribute() const;

///// OTHER PUBLIC FUNCTIONS
public:
	void printAttribute() const;
};

///////////////////////////////////////////////////////////////////////////////]
// DERIVED
class Child : public Default {
public:
	int is_crying;
};


#endif

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