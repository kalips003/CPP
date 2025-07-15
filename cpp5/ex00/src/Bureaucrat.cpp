#include "Bureaucrat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Bureaucrat::Bureaucrat(const std::string & name, int grade)
 : _name(name), _grade(grade) {
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
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
	if (_grade <= 1)
		throw GradeTooHighException();
	_grade--;
}
void	Bureaucrat::decrementGrade( void ) {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

///////////////////////////////////////////////////////////////////////////////]
std::ostream & operator<<( std::ostream& out, const Bureaucrat& jeff) {
	int	name = static_cast<int>(jeff.getName()[0]);
	out << "\e[38;5;" << name << "m" << jeff.getName() << RESET << ": bureaucrat [ " 
	<< "\e[38;5;" << jeff.getGrade() << "m" << jeff.getGrade() << RESET << " ]" << std::endl;
	return out;
}
///////////////////////////////////////////////////////////////////////////////]
const char* Bureaucrat::GradeTooHighException::what() const throw() {
	// return "Grade too High";
	return "\e[38;5;118mGrade too High\e[0m";
}
const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return "\e[38;5;124mGrade too Low\e[0m";
}
