#include "RobotomyRequestForm.hpp"

#include <unistd.h> // for sleep
#include <cstdlib>  // for srand, rand
#include <ctime>    // for time
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
 : AForm(C_321 "Robotomy Request" RESET, RRF_SIGN, RRF_EXEC), _target(target) {}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
 : AForm(other), _target(other._target) {}
RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {}
///////////////////////////////////////////////////////////////////////////////]
void	RobotomyRequestForm::doExecution() const {
	static bool seeded = false;
	if (!seeded) {
		std::srand(std::time(NULL));
		seeded = true;
	}
	
	std::string noise = "Brr";
	for (int i = 1; i < 7; i++) {
		std::cout << "\e[38;5;" << (i+63) << "m" << noise << std::string(i, ' ') << std::flush;
		noise += 'r';
		usleep(150000*i);  // 0.1 * i sec
	}

	if (rand() % 2)
		std::cout << std::endl << C_432"\t" << _target << RESET << " is now Happier! Look at him go!" << std::endl;
	else
		std::cout << std::endl << C_432"\t" << _target << RESET 
		<< "... I'm sorry but the procedure failed... \n\tbut you can agree to sell his organs to recover costs!!" << std::endl;
}
