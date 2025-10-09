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

/////////////////	DATA
private:
	std::vector<int>	_array;
	unsigned int		_max;

protected:

public:

/////////////////	CANONICAL
	Span(unsigned int max);
	Span(const Span &other);
	Span& operator=(const Span& other);
	~Span();

/////////////////	SETTER GETTER
	void	addNumber( int to_add );

	template <typename ITE>
	void	addLotsOfNumbers(ITE a, ITE b) {

		unsigned long distAB = static_cast<unsigned long>(std::distance(a, b));
		unsigned long distArray = static_cast<unsigned long>(_array.size());
		unsigned long distMin = distArray + distAB;
		if (distMin > _max) {
			std::cout << C_513 "Not enough space, copy reduced to fit" << std::endl;
			b -= distMin - _max;
		}
		_array.insert(_array.end(), a, b);	
		if (_array.size() > _max)
			std::cout << ERR "you should never see this" << std::endl;
	}

/////////////////	FUNCTIONS
	long	shortestSpan( void );
	long	longestSpan( void );

	void	randomSpan(int min, int max, size_t size);

/////////////////	TOOLS
	template <typename Iterator>
	static void	printSpan(Iterator start, Iterator end) {

		for (; start != end-1; start++)
			std::cout << C_512 << *start << RESET ", ";
		std::cout << C_512 << *(end-1) << RESET << std::endl;
	}

	std::vector<int>::const_iterator begin() const {
		return _array.begin();
	}
	std::vector<int>::const_iterator end() const {
		return _array.end();
	}
};

#endif
