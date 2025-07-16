#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>

#include "../_colors.h"

#include "AForm.hpp"
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
#define RRF_SIGN 72
#define RRF_EXEC 45
///////////////////////////////////////////////////////////////////////////////]
class RobotomyRequestForm : public AForm {

private:
	std::string _target;

protected:

public:

/////   CANONICAL
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm &other);
	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
	~RobotomyRequestForm();

/////
	void 	doExecution() const;

};
typedef RobotomyRequestForm RRF;

#endif
