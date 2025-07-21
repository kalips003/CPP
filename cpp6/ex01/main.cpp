#include "src/Serializer.hpp"

#include <iostream>

int main() {
	Data	d(2,3);

    std::cout << C_134 "Pointer: " RESET << &d << std::endl;
	uintptr_t i = Serializer::serialize(&d);
    std::cout << C_541 "Pointer as integer: " RESET << i << std::endl;

	Data *ptr = Serializer::deserialize(i);
    std::cout << C_522 "Value pointed to: " RESET << ptr << std::endl;
    std::cout << C_522 "Value of Data: " RESET << ptr->a << ", " << ptr->b << std::endl;

	return 0;
}

