#include "Span.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Span::Span(unsigned int max) : _max(max) {}

Span::Span(const Span &other) : _max(other._max) {
	for (unsigned int i = 0; i < other._array.size(); i++)
		_array.push_back(other._array.at(i));
}

Span& Span::operator=(const Span& other) {
	if (this != &other) {
		_array.clear();
		_max = other._max;
		for (unsigned int i = 0; i < other._array.size(); i++)
			_array.push_back(other._array.at(i));
	}
	return *this;
}

Span::~Span() {}

///////////////////////////////////////////////////////////////////////////////]
void	Span::addNumber( int to_add ) {
	if (_array.size() >= _max)
		throw std::runtime_error(ERR4 "Array full" RESET);
	_array.push_back(to_add);
}

///////////////////////////////////////////////////////////////////////////////]
long	Span::shortestSpan( void ) {
	if (_array.size() <= 1)
		throw std::runtime_error(ERR3 "No span can be found" RESET);

	std::vector<int> copy = _array;
	std::sort(copy.begin(), copy.end());
	
	long span = copy[1] - copy[0];
	int	 short0 = copy[0];
	int	 short1 = copy[1];
	for (size_t i = 1; i < copy.size() - 1; i++) {
		long temp = copy[i+1] - copy[i];
		if (temp < span) {
			span = temp;
			short0 = copy[i];	
			short1 = copy[i+1];	
		}
	}

	std::cout << C_425 "Shortest Span: [" RESET << short0 << C_425 ", " RESET
	<< short1 << C_425 "] (" C_113 << span << C_425 ")" RESET << std::endl;
	return span;
}

///////////////////////////////////////////////////////////////////////////////]
long	Span::longestSpan( void ) {
	if (_array.size() <= 1)
		throw std::runtime_error(ERR3 "No span can be found" RESET);

	int min = *std::min_element(_array.begin(), _array.end());
	int max = *std::max_element(_array.begin(), _array.end());

	std::cout << C_425 "Longest Span: [" RESET << min << C_425 ", " RESET
	<< max << C_425 "] (" C_113 << max - min << C_425 ")" RESET << std::endl;

	return max - min;

}

///////////////////////////////////////////////////////////////////////////////]
void	Span::randomSpan(int min, int max, size_t size) {
	static bool seeded = false;
	if (!seeded) {
		srand(std::time(NULL));
		seeded = true;
	}

	if (_array.size() + size > _max)
		size = _max - _array.size();
	if (min > max)
		throw std::runtime_error(ERR0 "Fix your input!" RESET);

	for (size_t i = 0; i < size; i++) {
		int randomN = std::rand() % (static_cast<long>(max) - min + 1) + min;
		_array.push_back(randomN);
	}
}