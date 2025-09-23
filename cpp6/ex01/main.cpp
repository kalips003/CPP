#include "src/Serializer.hpp"

#include <iostream>

int main() {
	Data	d(2,3);

    std::cout << std::endl << C_134 "Pointer: " RESET << &d << std::endl;
	uintptr_t i = Serializer::serialize(&d);
    std::cout << C_541 "Pointer as decimal: " RESET << i << std::endl;
    std::cout << C_541 "Pointer as hexadecimal: " RESET << std::hex << i << std::endl;

	Data *ptr = Serializer::deserialize(i);
    std::cout << C_522 "Value pointed to: " RESET << ptr << std::endl;
    std::cout << C_522 "Value of Data: " RESET << ptr->a << ", " << ptr->b << std::endl << std::endl;

	return 0;
}

