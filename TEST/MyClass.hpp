#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <string>

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

class MyClass {
private:
	/////   PRIVATE DATA
	int attribute, a, b;

public:
	/////   PUBLIC STANDARD FUNCIONS
	MyClass();
	MyClass(int value);
	MyClass(const MyClass& other);
	~MyClass();
	MyClass(int v, const std::string &n) : attribute(v), name(n) {}
	// MyClass& operator=(const MyClass& other);  // Copy assignment operator
	MyClass operator+(const MyClass &other);

	/////   PUBLIC SETTER GETTER
	void setAttribute(int value);	// Setter
	int getAttribute() const;		// Getter

	// OTHER PUBLIC FUNCTIONS
	void printAttribute() const;

	/////   PUBLIC DATA
	std::string name;

};

class Base {
public:
    void baseFunction() {}
};

class Derived : public Base {
public:
    void derivedFunction() {}
};

#endif