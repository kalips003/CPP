#include "Form.hpp"
#include "Bureaucrat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
AForm::AForm(const std::string &name, int gsign, int gexec)
 : _name(name), _signd(false), _grade_to_sign(gsign), _grade_to_exec(gexec) {
	if (gsign > LOWEST_GRADE || gexec > LOWEST_GRADE)
		throw GradeTooLowException();
	if (gsign < HIGHEST_GRADE || gexec < HIGHEST_GRADE)
		throw GradeTooHighException();
}
AForm::AForm(const AForm &other)
 : _name(other._name), _signd(other._signd), _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec) {}
AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		_signd = other._signd;	
	}
	return *this;
}
AForm::~AForm() {}
///////////////////////////////////////////////////////////////////////////////]
const std::string& AForm::getName( void ) const { return _name; }
bool AForm::isSigned( void ) const { return _signd; }
int AForm::getGradeSign( void ) const { return _grade_to_sign; }
int AForm::getGradeExec( void ) const { return _grade_to_exec; }
///////////////////////////////////////////////////////////////////////////////]
std::ostream& operator<<(std::ostream& out, const AForm& f) {
	out << "Form: " << C_343 << f.getName() << (f.isSigned() ? (C_140" ☑ ") : (C_401" ☐ "))
	<< RESET << "\n\tto sign: [" << C_431 << f.getGradeSign() << RESET << "]; to exec: ["
	<< C_431 << f.getGradeExec() << RESET << "]" << std::endl;
	return out;
}
const char* AForm::GradeTooHighException::what() const throw() {
	return "\e[38;5;118mGrade too High\e[0m";
}
const char* AForm::GradeTooLowException::what() const throw() {
	return "\e[38;5;124mGrade too Low\e[0m";
}

///////////////////////////////////////////////////////////////////////////////]
void	AForm::beSigned(const Bureaucrat& jeff) {
	if (jeff.getGrade() <= _grade_to_sign)
		_signd = true;
	else
		throw GradeTooLowException();
}

