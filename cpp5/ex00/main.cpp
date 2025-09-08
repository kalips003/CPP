#include "src/Bureaucrat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main()
{
	try {
		std::cout << REVERSE "\n\tA grade 1500 Bureaucrat?" RESET << std::endl;
		Bureaucrat a("leon", 1500);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	Bureaucrat b("Corrector", 1);
	Bureaucrat c("BIBI", 150);

//////////////////////////////////////]
	try {
		std::cout << "\n" << c << REVERSE "\tDecrement under 150?" RESET << std::endl;
		c.decrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

//////////////////////////////////////]
	try {
		std::cout << "\n" << b << REVERSE "\tIncrement above 1?" RESET << std::endl;
		b.incrementGrade();
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}

//////////////////////////////////////]
	std::cout << std::endl;
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