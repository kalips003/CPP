#include "src/Span.hpp"

#include <climits>

///////////////////////////////////////////////////////////////////////////////]
int main() {
	
	std::vector<int> numbers;

	Span	a(11000);
	numbers.push_back(12);
	numbers.push_back(20);
	numbers.push_back(30);

	numbers[0] += 10;
	numbers[4] += 10;

	a.randomSpan(INT_MIN, INT_MAX, 1000);
	a.printSpan(a.begin(), a.end());
	a.shortestSpan();
	a.longestSpan();

	return 0;
}