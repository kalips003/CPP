#include "MyClass.hpp"
#include <iostream>

//  DEFAULT CONSTRUCTOR
MyClass::MyClass() {
    attribute = 0;
}

//  VALUED CONSTRUCTOR
MyClass::MyClass() : attribute(0), name("") {
}

//  DEFUALT DESTRUCTOR
MyClass::~MyClass() {
}

//  COPY CONSTRUCTOR?
MyClass::MyClass(const MyClass &other) {
    attribute = other.attribute;
}

//  SETTER
void MyClass::setAttribute(int value) {
    attribute = value;
}

//  GETTER
int MyClass::getAttribute() const {
    return attribute;
}

////////////////////////////////////////////////]
//  OTHER FUNCTIONS
void MyClass::printAttribute() const {
    std::cout << "The attribute is: " << attribute << std::endl;    
}