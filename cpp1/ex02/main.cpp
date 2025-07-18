#include <string>
#include <iostream>

#include "_colors.h"

int main() {
    std::string string(C_535 "HI THIS IS BRAIN" RESET);
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << C_113 "Memory address of string: \n\t" RESET << &string << std::endl;
    std::cout << C_131 "Memory address held by string* ptr: \n\t" RESET << stringPTR << std::endl;
    std::cout << C_133 "Memory address of string& ref: \n\t" RESET << &stringREF << std::endl;
    
    std::cout << std::endl;
    std::cout << C_113 "Value of string: \n\t" RESET << string << std::endl;
    std::cout << C_131 "Value pointed to by string* ptr: \n\t" RESET << *stringPTR << std::endl;
    std::cout << C_133 "Value of string& ref: \n\t" RESET << stringREF << std::endl;

    return 0;
}