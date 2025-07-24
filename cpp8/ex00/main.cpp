#include "src/easyfind.hpp"

///////////////////////////////////////////////////////////////////////////////]
int main() {
	
	std::vector<int> numbers;

	numbers.push_back(12);
	numbers.push_back(20);
	numbers.push_back(30);

	numbers[0] += 10;
	numbers[4] += 10;

	for (size_t i = 0; i < numbers.size(); i++)
		std::cout << numbers[i] << " ";
	std::cout << std::endl << numbers[static_cast<int>(numbers.begin())] << std::endl;
	numbers.begin();

	return 0;
}