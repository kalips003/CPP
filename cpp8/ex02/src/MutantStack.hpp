#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
#include <stack>
#include <iterator>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T> {

public:
	typedef typename std::stack<T>::container_type::iterator iterator;

/////////////////	DATA		
private:

protected:

public:

/////////////////	CANONICAL
	MutantStack();
	MutantStack(const MutantStack &other);
	MutantStack& operator=(const MutantStack& other);
	~MutantStack();

/////////////////	OPERATORS
	T&			operator[](size_t index);
	iterator	begin();
	iterator	end();

};

#include "MutantStack.tpp"

#endif
