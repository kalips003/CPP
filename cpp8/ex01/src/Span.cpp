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

long	Span::shortestSpan( void ) {
	if (_array.size() <= 1)
		throw std::runtime_error(ERR3 "No span can be found" RESET);

	std::vector<int> copy = _array;
	std::sort(copy.begin(), copy.end());
	
	long span = copy[1] - copy[0];
	for (size_t i = 1; i < copy.size() - 1; i++) {
		long temp = copy[i+1] - copy[i];
		if (temp < span)
			span = temp;
	}

	return span;
}

long	Span::longestSpan( void ) {
	if (_array.size() <= 1)
		throw std::runtime_error(ERR3 "No span can be found" RESET);
	return *std::max_element(_array.begin(), _array.end());
}