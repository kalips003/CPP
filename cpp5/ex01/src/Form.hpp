#ifndef FORM_HPP
#define FORM_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <string>
#include <exception>

#include "../_colors.h"

class Bureaucrat;
///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
#define HIGHEST_GRADE 1
#define LOWEST_GRADE 150
///////////////////////////////////////////////////////////////////////////////]
class AForm {

private:
	const std::string _name;
	bool		_signd;
	const int	_grade_to_sign;
	const int	_grade_to_exec;
protected:

public:

/////   CANONICAL
	AForm(const std::string &name, int gsign, int gexec);
	AForm(const AForm &other);
	AForm& operator=(const AForm& other);
	~AForm();

/////   SETTER GETTER
	const std::string& getName( void ) const;
	bool isSigned( void ) const;
	int getGradeSign( void ) const;
	int getGradeExec( void ) const;

/////
	void	beSigned(const Bureaucrat& jeff);

/////   EXCEPTIONS
	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};

};

std::ostream& operator<<(std::ostream& out, const AForm& f);

#endif
