#ifndef DEFAULT_HPP
#define DEFAULT_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
// std::string
// #include <vector>
// #include <map>
// #include <set>
// #include <algorithm>
// #include <cstdlib>
// #include <cmath>
// #include <ctime>
// #include <iomanip>
// #include <sstream>
// #include <utility>
// #include <cassert>
// #include <cctype>
#include "_lib.hpp"

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

