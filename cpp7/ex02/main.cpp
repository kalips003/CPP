#include "src/Array.hpp"

#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////]
int main() {
	try {
		std::cout << C_410 REVERSE "Creating empty array of int...\n" RESET;
		Array<int> emptyArray;
		std::cout << emptyArray;

		std::cout << "\nCreating array of 5 ints...\n";
		Array<int> default_arr(5);
		std::cout << default_arr;

		std::cout << "\nFilling it...\n";
		for (size_t i = 0; i < default_arr.size(); ++i)
			default_arr[i] = static_cast<int>(i * 10);
		std::cout << "Elements in arr:\n";
		std::cout << default_arr;

		std::cout << C_410 REVERSE "\nTesting copy constructor...:" RESET;
		Array<int> copyArr(default_arr);
		copyArr[0] = 999;  // change to check independence
		std::cout << "\ncopy with first num changed...\n";
		std::cout << copyArr;
		std::cout << "original:\n";
		std::cout << default_arr;

		std::cout << C_410 REVERSE "\nTesting assignment operator..." RESET;
		Array<int> assignArr;
		assignArr = copyArr;
		assignArr[1] = 888;  // change to check independence
		std::cout << "\ncopy with second num changed...\n";
		std::cout << assignArr;
		std::cout << "original:\n";
		std::cout << copyArr;

		std::cout << C_410 REVERSE "\nTesting out-of-bounds access (should throw)...\n" RESET;
		std::cout << default_arr[10] << "\n";  // out of range, should throw

	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}

	return 0;
}
