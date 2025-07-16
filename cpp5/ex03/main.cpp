#include "src/Bureaucrat.hpp"
#include "src/AForm.hpp"
#include "src/ShrubberyCreationForm.hpp"
#include "src/RobotomyRequestForm.hpp"
#include "src/PresidentialPardonForm.hpp"
#include "src/Intern.hpp"

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
  
		SCF tree("you");
		RRF lobo("you");
		PPF pardon("you");

		std::cout << jeff << boss << intern << std::endl;

		jeff.signForm(pardon);
		boss.executeForm(pardon);
		jeff.executeForm(pardon);
		boss.signForm(pardon);
		jeff.executeForm(pardon);
		boss.executeForm(pardon);

	} catch (std::exception &e) {
		std::cout << "Exception caught: " << e.what() << std::endl;
	}
	Intern in;
	AForm *a = in.makeForm("Shrubbery creation", "the world");
	AForm *b = in.makeForm("Shrubbery creation", "yoiu");
	AForm *c = in.makeForm("Shruery creation", "Your mom");

	Bureaucrat boss("Boss", 1);

	if (a) {boss.signForm(*a); boss.executeForm(*a);}
	if (b) {boss.signForm(*b); boss.executeForm(*b);}
	if (c) {boss.signForm(*c); boss.executeForm(*c);}
	
	return 0;
}