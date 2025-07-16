#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

#include "AForm.hpp"
class	Bureaucrat;
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
#define PPF_SIGN 25
#define PPF_EXEC 5
///////////////////////////////////////////////////////////////////////////////]
class PresidentialPardonForm : public AForm {

private:
	std::string _target;
	
protected:

public:

/////   CANONICAL
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm &other);
	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
	~PresidentialPardonForm();

/////
	void 	doExecution() const;

};
typedef PresidentialPardonForm PPF;

#endif

