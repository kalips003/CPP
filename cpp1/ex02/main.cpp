#include <string>
#include <iostream>

int main() {
    std::string string("HI THIS IS BRAIN");
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Memory address of string: " << &string << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
        
    std::cout << "Value of string: " << string << std::endl;
    std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

    return 0;
}