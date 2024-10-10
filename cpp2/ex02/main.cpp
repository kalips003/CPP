#include <iostream>
#include "FixedNum.hpp"

int main(void) {
    try {
        FixedNum a(100.0f);  // Test with float
        std::cout << a.toInt() << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}