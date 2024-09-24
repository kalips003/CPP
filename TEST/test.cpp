
#include "src/_lib.hpp"
#include "src/Contact.hpp"

/*******************************************************************************
******************************************************************************/
// <!> - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  </!>
///////////////////////////////////////////////////////////////////////////////]
/*******************************************************************************

			░█████╗░  ███████╗░█████╗░██╗██████╗░███████╗
			██╔══██╗  ██╔════╝██╔══██╗██║██╔══██╗██╔════╝
			███████║  █████╗░░███████║██║██████╔╝█████╗░░
			██╔══██║  ██╔══╝░░██╔══██║██║██╔══██╗██╔══╝░░
			██║░░██║  ██║░░░░░██║░░██║██║██║░░██║███████╗
			╚═╝░░╚═╝  ╚═╝░░░░░╚═╝░░╚═╝╚═╝╚═╝░░╚═╝╚══════╝

┌───┬───┐
│   │   │
├───┼───┤
│   │   │
└───┴───┘

template class, template argument ,  static member function??
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main() {
    std::string input;

    while (true) {
        std::cout << "Enter input (Ctrl+D to simulate EOF): ";

        // Attempt to read input using std::cin
        if (!(std::cin >> input)) {
            if (std::cin.eof()) {
                std::cin.clear();  // Clear the EOF flag
                std::cout << "\nEOF reached. Please enter input again." << std::endl;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard remaining input
                continue;  // Prompt again for input
            } else {
                std::cerr << "Error reading input!" << std::endl;
                break;
            }
        }

        // Process the input if cin >> input succeeds
        std::cout << "You entered: " << input << std::endl;
    }

    return 0;
}
///////////////////////////////////////////////////////////////////////////////]


/*******************************************************************************

std::string:

    size() / length()
		Returns the number of characters.
    empty()
		Checks if the string is empty.
    clear()
		Clears the string (makes it empty).
    at(size_type pos)
		Accesses the character at a specific position (with bounds checking).
    operator[]
		Accesses a character at a specific position (without bounds checking).
    append(const std::string&)
		Appends another string.
    substr(size_type pos, size_type len)
		Returns a substring.
    find(const std::string&)
		Finds the first occurrence of a substring.
    compare(const std::string&)
		Compares two strings.
    c_str()
		Returns a C-style string (const char*).
    replace(size_type pos, size_type len, const std::string&)
		Replaces part of the string with another.
    insert(size_type pos, const std::string&)
		Inserts another string at a position.
    erase(size_type pos, size_type len)
		Erases part of the string.
    push_back(char)
		Appends a character.
    pop_back()
		Removes the last character.
    resize(size_type newSize)
		Resizes the string to a new size.
    swap(std::string&)
		Swaps the contents of two strings.

std::getline(std::istream& input, std::string& str);










template <typename T>
T add(T a, T b) {
    return a + b;
}


template <typename T>
class Box {
public:
    T value; // value can be of any type T
    Box(T v) : value(v) {}
};






// User-Defined Types

struct Point {
    int x;
    int y;
};

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
};

enum Color {
    RED,
    GREEN,
    BLUE
};

union Data {
    int intValue;
    float floatValue;
    char charValue;
};

// Standard Library Types

#include <vector>
std::vector<int> numbers;  // Dynamic array

#include <list>
std::list<int> myList;     // Doubly linked list

#include <map>
std::map<std::string, int> ages;  // Key-value pairs

#include <utility>
std::pair<int, std::string> person;  // Pair of two types

#include <string>
std::string name;  // String type

******************************************************************************/


