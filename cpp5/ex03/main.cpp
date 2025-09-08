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
// { "Shrubbery creation", "Robotomy Request", "Presidential Pardon" };
///////////////////////////////////////////////////////////////////////////////]
int main() {

	Intern in;
	AForm *a = in.makeForm("Shrubbery creation", "the world");
	AForm *b = in.makeForm("Shrubbery creation", "yoiu");
	AForm *c = in.makeForm("Shruery creation", "Your mom");

std::cout << std::endl;///////////////////////////////////]

	Bureaucrat boss("Boss", 1);

	if (a) {boss.signForm(*a); boss.executeForm(*a);}
std::cout << std::endl;///////////////////////////////////]
	if (b) {boss.signForm(*b); boss.executeForm(*b);}
std::cout << std::endl;///////////////////////////////////]
	if (c) {boss.signForm(*c); boss.executeForm(*c);}
	
	return 0;
}