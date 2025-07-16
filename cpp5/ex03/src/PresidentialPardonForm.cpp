#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
 : AForm(C_123 "Presidential Pardon" RESET, PPF_SIGN, PPF_EXEC), _target(target) {}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
 : AForm(other), _target(other._target) {}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
PresidentialPardonForm::~PresidentialPardonForm() {}
///////////////////////////////////////////////////////////////////////////////]
void	PresidentialPardonForm::doExecution() const {
	std::cout << C_432 << _target << RESET << " has been pardoned by the great Zaphod Beeblebrox." << std::endl;
}

