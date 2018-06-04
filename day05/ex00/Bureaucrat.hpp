//
// Created by Alexis LEVEQUE on 6/4/18.
//

#ifndef EX00_BUREAUCRAT_HPP
#define EX00_BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

public:

	class GradeTooHighException : public std::exception {
		public:
		virtual const char* what() const throw() {
			return ("Grade is too high");
		}
	};


	class GradeTooLowException : public std::exception {
		public:
		virtual const char* what() const throw() {
			return ("Grade is too low");
		}
	};

	Bureaucrat(std::string, int);

	Bureaucrat(Bureaucrat const &src);

	Bureaucrat &operator=(Bureaucrat const &rhs);

	~Bureaucrat(void);

	std::string		getName()const;
	int 			getGrade() const;
	void			incrementGrade();
	void			decrementGrade();

protected:
	Bureaucrat(void);

private:
	std::string const	_name;
	int 				_grade;
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif //EX00_BUREAUCRAT_HPP
