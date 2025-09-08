#include "src/Bureaucrat.hpp"
#include "src/AForm.hpp"
#include "src/ShrubberyCreationForm.hpp"
#include "src/RobotomyRequestForm.hpp"
#include "src/PresidentialPardonForm.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
// •ShrubberyCreationForm: 	sign 145, exec 137
// •RobotomyRequestForm: 	sign 72, exec 45
// •PresidentialPardonForm: sign 25, exec 5
///////////////////////////////////////////////////////////////////////////////]
int main() {
	try {
		Bureaucrat boss("Boss", 1);
		Bureaucrat jeff("Jeff", 50);
		Bureaucrat intern(RED"Intern", 150);
  
		std::cout << jeff << boss << intern << std::endl;

		SCF tree("you");
		RRF lobo("you");
		PPF pardon("you");

		std::cout << tree << lobo << pardon << std::endl;

		jeff.signForm(pardon);
		boss.executeForm(pardon);
		jeff.executeForm(pardon);
		boss.signForm(pardon);
		jeff.executeForm(pardon);
		std::cout << std::endl;
		boss.executeForm(pardon);

	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	RRF lobo("your mom");
	lobo.doExecution();

	std::cout << std::endl;
	SCF tree("home");
	tree.doExecution();

	return 0;
}