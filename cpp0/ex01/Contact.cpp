#include "Contact.hpp"
#include <iostream>

//  DEFAULT CONSTRUCTOR
Contact::Contact() {
    first_name = "";
    last_name = "";
    nickname = "";
    darkest_secret = "";
    phone_number = "";
}

//  DEFUALT DESTRUCTOR
Contact::~Contact() {
}

//  SETTER
void Contact::setFirstName(char *value) {
    first_name = value;
}
//  SETTER
void Contact::setAttribute(char *value) {
    attribute = value;
}

//  GETTER
int Contact::getAttribute() const {
    return attribute;
}

////////////////////////////////////////////////]
//  OTHER FUNCTIONS
void Contact::printAttribute() const {
    std::cout << "The attribute is: " << attribute << std::endl;    
}