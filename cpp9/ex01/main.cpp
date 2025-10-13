
#include "_colors.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>

//  "8 9 * 9 - 9 - 9 - 4 - 1 +"
struct t_stack {
	std::stack<int> _stack;

///////////////////////////////////]
	void	addline(const char *input) {

		std::stringstream ss(input);

		std::string symbol;
		while (ss >> symbol)
			handleOneSymbol(symbol);

		printStack();
	}

///////////////////////////////////]
	void	handleOneSymbol(std::string& symbol) {

		std::string operators = "+-*/";
		size_t	pos = operators.find(symbol[0]);

		if (pos != std::string::npos) {
			if (symbol.size() != 1)
				pos = 7;// bad input
			doTheMath(pos, symbol);
		}
		else if (std::isdigit(symbol[0])) {
			char *end(NULL);
			long num = std::strtol(symbol.c_str(), &end, 10);
			if (*end)
				std::cout << ERR5 "// bad number: (" << symbol << ")" << std::endl;// bad number
			else if (num > 10 || num < 0)
				std::cout << ERR6 "// big number: (" << symbol << ")" << std::endl;// big number
			else {
				_stack.push(num); 

			}
		}
		else
			std::cout << ERR7 "// bad input: (" << symbol << ")" << std::endl;// bad input

	}

///////////////////////////////////]
	void	doTheMath(size_t pos, std::string& symbol) {
		if (_stack.size() < 2) {
			std::cout << C_520 "stack too small for operation (ignored)" RESET << std::endl;
			return;
		}

		int a = _stack.top();
		_stack.pop();
		int b = _stack.top();

		switch (pos) {

			case 0:// '+' 
				_stack.top() = b + a; break;
			case 1:// '-' 
				_stack.top() = b - a; break;
			case 2:// '*' 
				_stack.top() = b * a; break;
			case 3:// '/' 
				if (b != 0) {_stack.top() = b / a;} break;
			default:// bad input
				std::cout << ERR3 "// bad input ignored: (" << symbol << ")" << std::endl; return;
		}
		std::cout << ">   " C_520 << b << RESET " " << symbol << " " C_250 << a << RESET " = " << _stack.top() << std::endl;
	}
///////////////////////////////////]
	void	printStack() {
		std::stack<int> temp(_stack);
		bool 	first(true);

		std::cout << "[";
		while (!temp.empty()) {
			if (!first) std::cout << ", ";
			std::cout << C_451 << temp.top() << RESET;
			temp.pop();
			first = false;
		}
		std::cout << "]" << std::endl;
	}
};
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
//  "8 9 * 9 - 9 - 9 - 4 - 1 +"
///////////////////////////////////////////////////////////////////////////////]
int main(int ac, char** av)
{
	t_stack	stack;

	if (ac == 1) {

		std::string prompt;
		std::cout << C_253 "input:\n" RESET;
		while (std::cin >> prompt)
			stack.addline(prompt.c_str());
		return 0;
	}

	// std::cout << C_253 "input: " RESET << ac << std::endl;
	// for (int i = 1; i < ac; i++)
	// 	std::cout << C_253 << av[i] << ", " RESET;

		// stack.addline(av[i]);
	while (*(++av))
		stack.addline(*av);

	return 0;
}