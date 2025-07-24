#include "src/Span.hpp"

///////////////////////////////////////////////////////////////////////////////]
int main() {
	
	std::vector<int> numbers;

	Span	a(11000);
	numbers.push_back(12);
	numbers.push_back(20);
	numbers.push_back(30);

	numbers[0] += 10;
	numbers[4] += 10;



	return 0;
}