#include "src/Array.hpp"

#include <iostream>
#include <string>

///////////////////////////////////////////////////////////////////////////////]
int main() {
	try {
		std::cout << "Creating empty array of int...\n";
		Array<int> emptyArray;
		std::cout << "Size: " << emptyArray.size() << "\n";

		std::cout << "\nCreating array of 5 ints...\n";
		Array<int> arr(5);
		for (size_t i = 0; i < arr.size(); ++i)
			arr[i] = static_cast<int>(i * 10);

		std::cout << "Elements in arr:\n";
		for (size_t i = 0; i < arr.size(); ++i)
			std::cout << arr[i] << " ";
		std::cout << "\n";

		std::cout << "\nTesting copy constructor...\n";
		Array<int> copyArr(arr);
		copyArr[0] = 999;  // change to check independence

		std::cout << "Original arr[0]: " << arr[0] << "\n";
		std::cout << "Copy copyArr[0]: " << copyArr[0] << "\n";

		std::cout << "\nTesting assignment operator...\n";
		Array<int> assignArr;
		assignArr = arr;
		assignArr[1] = 888;  // change to check independence

		std::cout << "Original arr[1]: " << arr[1] << "\n";
		std::cout << "Assigned assignArr[1]: " << assignArr[1] << "\n";

		std::cout << "\nTesting out-of-bounds access (should throw)...\n";
		std::cout << arr[10] << "\n";  // out of range, should throw

	} catch (const std::exception& e) {
		std::cerr << "Caught exception: " << e.what() << "\n";
	}

	return 0;
}