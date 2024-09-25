#include "_.hpp"

///////////////////////////////////////////////////////////////////////////////]
//  DEFAULT CONSTRUCTOR
Default::Default() : attribute(0), label("") {}

//  DEFAULT DESTRUCTOR
Default::~Default() {}

//  COPY CONSTRUCTOR
Default::Default(const Default &other) { attribute = other.attribute; }

//  SETTER
void Default::setAttribute(int value) {	attribute = value; }
//  GETTER
int Default::getAttribute() const {	return attribute; }

///////////////////////////////////////////////////////////////////////////////]
//  OTHER FUNCTIONS
void Default::printAttribute() const {
	std::cout << "The attribute is: " << attribute << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
// External /  Template
template <typename T1, typename T2>
void showTypes(T1 val1, T2 val2) {
	std::cout << "First type: " << typeid(val1).name() << std::endl;
	std::cout << "Second type: " << typeid(val2).name() << std::endl;
}