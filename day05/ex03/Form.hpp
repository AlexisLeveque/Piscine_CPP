//
// Created by Alexis LEVEQUE on 6/4/18.
//

#ifndef EX01_FORM_HPP
#define EX01_FORM_HPP


#include <iostream>

class 	Bureaucrat;

class Form {

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

	class FormNotSignedException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Form is not signed");
		}
	};

public:
	Form(std::string name, int sign, int exec);

	Form(Form const &src);

	Form &operator=(Form const &rhs);

	virtual ~Form(void);

	void 	beSigned(Bureaucrat &someone);
	virtual void execute(Bureaucrat const & executor) const;

	std::string		getName() const;
	bool			getSign() const;
	int				getSignGrade() const;
	int				getExecGrade() const;

	void			setSign();

protected:
	Form(void);

private:
	std::string	const	_name;
	bool				_sign;
	int 		const	_signGrade;
	int			const	_execGrade;

};

std::ostream &operator<<(std::ostream &o, Form const &rhs);


#endif //EX01_FORM_HPP
