#ifndef INTERN_HPP
#define INTERN_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

class AForm;
class ShrubberyCreationForm;
class RobotomyRequestForm;
class PresidentialPardonForm;

struct FormNode {
	AForm* form;
	FormNode* next;
};

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
#define DRAWER_SIZE 3
///////////////////////////////////////////////////////////////////////////////]
class Intern {

private:
	FormNode *_head_pile;

	AForm* addForm(AForm* new_form);
	void	cleanUp( void );
	
protected:

public:

/////   CANONICAL
	Intern();
	Intern(const Intern &other);
	Intern& operator=(const Intern& other);
	~Intern();

/////
	AForm* makeForm(const std::string &name, const std::string &target);
	AForm* makeSCF(const std::string &target) const;
	AForm* makeRRF(const std::string &target) const;
	AForm* makePPF(const std::string &target) const;

};

#endif
