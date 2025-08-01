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

private:

protected:

public:

/////   CANONICAL
	MutantStack() {};
	MutantStack(const MutantStack &other) : std::stack<T>(other) {};
	MutantStack& operator=(const MutantStack& other) {
		if (this != &other)
			std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack() {}

/////   SETTER GETTER
	T&	operator[](size_t index) {
		return this->c[index];
	}
	iterator	begin() {
		return this->c.begin();
	}
	iterator	end() {
		return this->c.end();
	}

};

#endif
