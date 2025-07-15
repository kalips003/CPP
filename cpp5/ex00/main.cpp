#include "src/Bureaucrat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main()
{
	try {
		Bureaucrat a("leon", 1500);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat b("Corrector", 100);
	Bureaucrat c("BIBI", 150);

	try {
		c.decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << b;

	for (int i = 0; i < 155; i++) {
		std::cout << c;
		try {
			c.incrementGrade();
		} catch (std::exception & e) {
			std::cout << e.what() << std::endl;
			break ;
		}
	}
	return 0;
}