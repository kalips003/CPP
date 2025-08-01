#include "src/MutantStack.hpp"

#include <climits>

///////////////////////////////////////////////////////////////////////////////]
// int main() {
	
// 	MutanStack<int>	s;

// 	s.push(4);
// 	s.push(5);
// 	s.push(6);
// 	s.push(26);

// 	std::cout << C_150 "element[i]: " RESET << s[2] << std::endl;
// 	std::cout << C_150 "last element: " RESET << *(--s.end()) << std::endl;
// 	std::cout << C_150 "first element: " RESET << *s.begin() << std::endl;

// 	return 0;
// }

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}