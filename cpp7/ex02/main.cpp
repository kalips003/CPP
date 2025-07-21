#include "src/Array.hpp"

#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////]
int main() {

    int arrayA[] = {2,8,5846,84,8,6,4,6,4,46};
    size_t  sizeA = 10;

    std::string arrayB[] = {"2,8,5846,84,8,6,4,6,4,46", "Hello les enfants", "HI EVERYONE", "BLBLBLBLBLBLBL"};
    size_t  sizeB = 4;

    iter(arrayA, sizeA, &ft_print);
    std::cout << std::endl;
    iter(arrayB, sizeB, &ft_print);
    std::cout << std::endl;
	return 0;
}
