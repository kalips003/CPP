#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

///////////////////////////////////////////////////////////////////////////////]
// 									LIBs
#include <iostream>
#include <exception>
#include <string>

#include "../_colors.h"

///////////////////////////////////////////////////////////////////////////////]
// 									CLASS
///////////////////////////////////////////////////////////////////////////////]
class Bureaucrat {

private:
	const std::string _name;
	int		_grade;

protected:

public:

/////   CANONICAL
	Bureaucrat(const std::string & name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

/////   SETTER GETTER
	const std::string& getName() const;
	int getGrade() const;
	void	incrementGrade( void );
	void	decrementGrade( void );

/////
	class GradeTooHighException : public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		virtual const char* what() const throw();
	};
};

std::ostream & operator<<( std::ostream& out, const Bureaucrat& jeff);

#endif

