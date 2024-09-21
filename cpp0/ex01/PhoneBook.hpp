#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <string>

class MyClass {
private:
    /////   PRIVATE DATA
    char *contacts[8];

public:
    /////   PUBLIC STANDARD FUNCIONS
    MyClass();
    MyClass(int value);
    MyClass(const MyClass& other);
    ~MyClass();
    // MyClass& operator=(const MyClass& other);  // Copy assignment operator

    /////   PUBLIC SETTER GETTER
    void setAttribute(int value);    // Setter
    int getAttribute() const;        // Getter

    // OTHER PUBLIC FUNCTIONS
    void printAttribute() const;

    /////   PUBLIC DATA
    std::string name;

};

#endif