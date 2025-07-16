#include "Bureaucrat.hpp"

#include <sstream>
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Bureaucrat::Bureaucrat(const std::string & name, int grade)
 : _name(name), _grade(grade) {
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
}
Bureaucrat::Bureaucrat(const Bureaucrat &other)
 : _name(other._name), _grade(other._grade) {}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		_grade = other._grade;
	return *this;
}
Bureaucrat::~Bureaucrat() {}
///////////////////////////////////////////////////////////////////////////////]
const std::string& Bureaucrat::getName() const {
	return _name;
}
int Bureaucrat::getGrade() const {
	return _grade;
}
void	Bureaucrat::incrementGrade( void ) {
	if (_grade <= HIGHEST_GRADE)
		throw GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade( void ) {
	if (_grade >= LOWEST_GRADE)
		throw GradeTooLowException();
	_grade++;
}
///////////////////////////////////////////////////////////////////////////////]
std::ostream & operator<<( std::ostream& out, const Bureaucrat& jeff) {
	out << jeff.printName() << ": bureaucrat [ " "\e[38;5;" << jeff.getGrade() 
	<< "m" << jeff.getGrade() << RESET " ]" << std::endl;
	return out;
}
///////////////////////////////////////////////////////////////////////////////]
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return "\e[38;5;118mGrade too High\e[0m";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "\e[38;5;124mGrade too Low\e[0m";
}

///////////////////////////////////////////////////////////////////////////////]
void	Bureaucrat::signForm(AForm& form) const {

	try {
		form.beSigned(*this);
	} catch (std::exception& e) {
		std::cout << printName() << " couldn't sign form (" C_515 
		<< form.getName() << RESET") because: " << e.what() << std::endl;
		return;
	}
	std::cout << printName() << " signed " C_515 << form.getName() << RESET << std::endl;
}

void 	Bureaucrat::executeForm(AForm const & form) const {

	try {
		form.execute(*this);
	} catch (std::exception& e) {
		std::cout << printName() << " couldn't execute form (" C_515 
		<< form.getName() << RESET") because: " << e.what() << std::endl;
		return;
	}
	std::cout << printName() << " executed " C_515 << form.getName() << RESET << std::endl;
}

std::string Bureaucrat::printName( void ) const {

	std::stringstream s;
	s << "\e[38;5;" << static_cast<int>(_name[0]) << "m" << getName() << RESET;
	return s.str();
}