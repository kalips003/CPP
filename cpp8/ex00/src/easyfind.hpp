#ifndef EASYFIND_HPP
#define EASYFIND_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
template <typename T>
typename T::iterator	easyfind(T& tofind, int i) {
	typename T::iterator it = std::find(tofind.begin(), tofind.end(), i);
	if (it == tofind.end())
		return tofind.end();
		// throw std::runtime_error(err6 "Not found" RESET);
	return it;
}


#endif
