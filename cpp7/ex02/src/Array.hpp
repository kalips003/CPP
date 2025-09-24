#ifndef ARRAY_HPP
#define ARRAY_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
#include <exception>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
template <typename T>
class Array {

private:
	size_t	_size;
	T*		_array;
protected:

public:

/////   CANONICAL
	Array();
	Array(unsigned int n);
	Array(const Array &other);
	Array& operator=(const Array& other);
	const T& operator[](size_t index) const;
	T& operator[](size_t index);
	~Array();

/////   SETTER GETTER
	size_t size( void ) const;

/////   EXCEPTION
	class OutOfBounds : public std::exception {
		virtual const char* what() const throw();
	};

};

template <typename T>
std::ostream& operator<<(std::ostream& s, const Array<T>& a) {
	if (a.size() == 0) {
		s << C_410 "\t[ " RESET "EMPTY" C_410 " ]" RESET << std::endl;
		return s;
	}

	size_t	j = a.size() - 1;
	size_t i = -1;
	s << C_410 "[ " RESET << j << C_410 " ]" RESET ": ";
	while (++i < j)
		s << C_410 << a[i] << RESET ", ";
	s << C_410 << a[i] << RESET "." << std::endl;

	return s;
}

#include "Array.tpp"

#endif
