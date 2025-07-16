#include "src/Bureaucrat.hpp"
#include "src/Form.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
int main() {
	try {
		Bureaucrat jeff("Jeff", 50);
		Bureaucrat boss("Boss", 1);
		Bureaucrat intern("Intern", 150);

		AForm taxForm("Can i go to the toilet?", 100, 50);
		AForm secretForm("Top Secret", 1, 1);

		std::cout << jeff << std::endl;
		std::cout << boss << std::endl;
		std::cout << intern << std::endl;

		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		intern.signForm(taxForm);
		jeff.signForm(taxForm);
		boss.signForm(secretForm);

		std::cout << taxForm << std::endl;
		std::cout << secretForm << std::endl;

		AForm invalidForm("Invalid", 0, 160);

		std::cout << "This shouldnt print" << std::endl;

	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	return 0;
}