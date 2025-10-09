#include "src/Span.hpp"

#include <climits>

///////////////////////////////////////////////////////////////////////////////]
int main() {
	
	int	lst[] = {0,1,2,3,4,5};
	Span	b(10);
	b.addLotsOfNumbers(lst, lst + sizeof(lst)/sizeof(int));
	Span::printSpan(b.begin(), b.end());
	std::cout << std::endl;

	std::vector<int> numbers;
	numbers.push_back(111);
	numbers.push_back(222);
	numbers.push_back(333);

	Span	a(11000);
	a.randomSpan(0, 9999, 100);
	// a.randomSpan(INT_MIN, INT_MAX, 1000);
	a.addLotsOfNumbers(numbers.begin(), numbers.end());

	Span::printSpan(a.begin(), a.end());
	a.shortestSpan();
	a.longestSpan();

	return 0;
}