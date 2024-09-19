#ifndef CLASS_HPP
#define CLASS_HPP

#include <string>

class Class {
public:
    // Constructor
    Class(const std::string& fName = "", const std::string& lName = "");

    // Member variables
    std::string firstName;
    std::string lastName;

    // Member function
    void printName() const;
};

#endif