#ifndef SPAN_HPP
#define SPAN_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <ctime>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class Span {

private:
	std::vector<int>	_array;
	unsigned int		_max;
protected:

public:

/////   CANONICAL
	Span(unsigned int max);
	Span(const Span &other);
	Span& operator=(const Span& other);
	~Span();

/////   SETTER GETTER
	void	addNumber( int to_add );
/////
	long	shortestSpan( void );
	long	longestSpan( void );

	template <typename Iterator>
	void	addNumber(Iterator start, Iterator end) {
		if (_array.size() + std::distance(start, end) > _max)
			throw std::runtime_error(ERR8 "Not enough space" RESET);
		_array.insert(_array.end(), start, end);
	}

	void	randomSpan(int min, int max, size_t size) {
		static bool seeded = false;
		if (!seeded) {
			srand(std::time(NULL));
			seeded = true;
		}

		if (_array.size() + size > _max)
			throw std::runtime_error(ERR8 "Not enough space" RESET);
		if (min > max)
			throw std::runtime_error(ERR0 "Fix your input!" RESET);
		for (size_t i = 0; i < size; i++) {
			int randomN = std::rand() % (max - min + 1) + min;
			_array.push_back(randomN);
		
		}
	}

	void	printSpan();
};

#endif
