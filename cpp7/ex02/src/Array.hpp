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

#include "Array.tpp"

#endif
