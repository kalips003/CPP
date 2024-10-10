#include <iostream>
#include "FixedNum.hpp"
#include "_colors.h"

int main(void) {
    FixedNum a(1.01f);
    FixedNum b(4);
    FixedNum c = a * b;
    put(c);
    std::cout << C_123 "a = " << a << std::endl;
    std::cout << C_033 "b = " << b << std::endl;
    std::cout << C_115 "a > b ? : " << (a > b) << std::endl;
    return 0;
}