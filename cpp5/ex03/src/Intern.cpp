#include "Intern.hpp"

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
Intern::Intern() : _head_pile(NULL) {}
Intern::Intern(const Intern &other) : _head_pile(NULL) { (void)other; }
Intern& Intern::operator=(const Intern& other) {
	if (this != &other)
		(void)other;
	return *this;
}
Intern::~Intern() { cleanUp(); }
///////////////////////////////////////////////////////////////////////////////]
AForm* Intern::makeForm(const std::string &name, const std::string &target) {

	typedef AForm* (Intern::*MakeFunc)(const std::string &) const;
	MakeFunc forms_funcs[3] = { &Intern::makeSCF, &Intern::makeRRF, &Intern::makePPF };

	std::string	drawers[3] = { "Shrubbery creation", "Robotomy Request", "Presidential Pardon" };
	
	int i = -1;
	while (++i < DRAWER_SIZE) {
		if (drawers[i] == name) {
			std::cout << C_543 << "Intern creates: " << name << std::endl;
			return addForm((this->*forms_funcs[i])(target));
		}
	}
	std::cout << C_511 << "ERROR - I don't have any '" << name << "' forms..." << std::endl;
	return NULL;
}

AForm* Intern::makeSCF(const std::string &target) const {
	return new ShrubberyCreationForm(target);
}
AForm* Intern::makeRRF(const std::string &target) const {
	return new RobotomyRequestForm(target);
}
AForm* Intern::makePPF(const std::string &target) const {
	return new PresidentialPardonForm(target);
}

///////////////////////////////////////////////////////////////////////////////]
AForm* Intern::addForm(AForm* new_form) {
	if (!new_form)
		return NULL;

	FormNode* newNode = new FormNode;
	newNode->form = new_form;
	newNode->next = NULL;

	if (!_head_pile) {
		_head_pile = newNode;
	} else {
		FormNode *last = _head_pile;
		while (last && last->next)
			last = last->next;
		last->next = newNode;
	}
	
	return new_form;
}

void	Intern::cleanUp( void ) {

	FormNode* tmp;
	while (_head_pile) {
		tmp = _head_pile;
		_head_pile = _head_pile->next;
		delete tmp->form;
		delete tmp;
	}
	_head_pile = NULL;
}