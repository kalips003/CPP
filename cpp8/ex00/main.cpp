#include "src/easyfind.hpp"

///////////////////////////////////////////////////////////////////////////////]
// vector<T>	Dynamic array; random access; fast push_back	
	// push_back, size, operator[], begin, end, insert, erase
// deque<T>	Double-ended queue; fast insert/delete at both ends	
	// push_back, push_front, pop_back, pop_front, operator[]
// list<T>	Doubly linked list; slow random access, fast insert/delete anywhere	
	// push_back, push_front, insert, erase, splice
// queue<T>	FIFO; uses underlying container	
	// push, pop, front, back
// stack<T>	LIFO; uses underlying container	
	// push, pop, top
///////////////////////////////////////////////////////////////////////////////]
// set<T>	Unique, ordered elements	
	// insert, find, erase
// multiset<T>	Allows duplicates, ordered	
	// insert, find, erase
// map<Key,Value>	Unique keys; sorted; access via key	
	// insert, operator[], find, erase
// multimap<Key,Value>	Allows duplicate keys	
	// insert, find, erase
///////////////////////////////////////////////////////////////////////////////]
// size()	Returns number of elements
// empty()	Returns true if container is empty
// clear()	Removes all elements
// insert()	Inserts elements (position-specific for some containers)
// erase()	Removes elements (by iterator or key)
// begin(), end()	Iterators to start and past-the-end
// rbegin(), rend()	Reverse iterators
// front(), back()	Access first/last elements
///////////////////////////////////////////////////////////////////////////////]
// ITERATOR
///////////////////////////////////////////////////////////////////////////////]
// sort(begin,end)	Sort elements
// reverse(begin,end)	Reverse elements
// find(begin,end,val)	Find element
// count(begin,end,val)	Count occurrences
// accumulate(begin,end,init)	Sum/accumulate (requires <numeric>)
// for_each(begin,end,func)	Apply function to all elements
// copy(begin,end,dest)	Copy range
// remove, remove_if	Remove elements based on value
///////////////////////////////////////////////////////////////////////////////]
int main() {
	
	int arr[] = {1,2,3,4,5,6123,14,15,15,31,51,1,53,3535,4,658,65,53,73,6,73};

	std::vector<int> numbers;

	numbers = std::vector<int>(arr, arr + sizeof(arr)/sizeof(int));

	numbers.push_back(999);
	numbers.push_back(0);
	numbers.push_back(9999);

	numbers[0] += 10;
	numbers[4] += 10;		

	std::cout << RESET "[";
	for (size_t i = 0; i < numbers.size() - 1; i++) {
		std::cout << "\e[38;5;" << 2 + i << "m";
		std::cout << numbers[i] << RESET ", ";
		// std::cout << *(numbers.begin() + i);
	}
	std::cout << numbers.back() << "]\n" << std::endl;

	int	to_find = 31;
	std::vector<int>::iterator it = easyfind(numbers, to_find);
	if (it == numbers.end())
		std::cout << RED REVERSE << to_find << RED " Can't be found\n" << std::endl;
	else
		std::cout << GREEN REVERSE << to_find << GREEN " Found at index position: " RESET << it - numbers.begin() << "\n\n" << std::endl;

	return 0;		
}