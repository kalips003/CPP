#include "ShrubberyCreationForm.hpp"

#include <stdlib.h>
#include <fstream>
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
///////////////////////////////////////////////////////////////////////////////]
ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
 : AForm(C_213 "Shrubbery creation" RESET, SCF_SIGN, SCF_EXEC), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
 : AForm(other), _target(other._target) {}
ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		_target = other._target;
	}
	return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {}
///////////////////////////////////////////////////////////////////////////////]
void	ShrubberyCreationForm::doExecution() const {
	std::ofstream file((_target + "_shrubbery").c_str());

	file << TREE;
	std::cout << C_151 "Tree has been planted in: " C_445 << _target << "_shrubbery" RESET << std::endl;
	file.close();
}
