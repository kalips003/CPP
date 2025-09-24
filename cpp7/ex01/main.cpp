#include "src/iter.hpp"

#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////]
int main() {

    int arrayA[] = {2,8,5846,84,8,6,4,6,4,46};
    size_t  sizeA = sizeof(arrayA) / sizeof(int);

    std::string arrayB[] = {"2,8,5846,84,8,6,4,6,4,46", "Hello les enfants", "HI EVERYONE", "BLBLBLBLBLBLBL"};
    size_t  sizeB = sizeof(arrayB) / sizeof(arrayB[0]);

    std::cout << C_312 "ITER of arrayA of size " RESET<< sizeA << std::endl;
    iter(arrayA, sizeA, &ft_print);
    std::cout << std::endl << std::endl;
    std::cout << C_350 "ITER of arrayB of size " RESET<< sizeB << std::endl;
    iter(arrayB, sizeB, &ft_print);
    std::cout << std::endl;
	return 0;
}
