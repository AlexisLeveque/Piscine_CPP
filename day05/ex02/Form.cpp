//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form(void) : _name("Default"), _signGrade(150), _execGrade(150) {}

Form::Form(std::string name, int sign, int exec) : _name(name), _sign(false), _signGrade(sign), _execGrade(exec) {
	if (sign < 1 || exec < 1) {
		throw Form::GradeTooHighException();
	}
	if (sign > 150 || exec > 150) {
		throw Form::GradeTooLowException();
	}
}

Form::Form(Form const &src) : _name(src.getName()), _sign(src.getSign()), _signGrade(src.getSignGrade()), _execGrade(src.getExecGrade()){}

Form &Form::operator=(Form const &rhs) {
	_sign = rhs.getSign();
	return *this;
}

Form::~Form(void) {}

void Form::beSigned(Bureaucrat &someone) {
	if (someone.getGrade() <= this->getSignGrade()) {
		_sign = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

void Form::execute(Bureaucrat const & executor) const {
	(void)executor;
}

std::string Form::getName() const {
	return _name;
}

bool Form::getSign() const {
	return _sign;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

void Form::setSign() {
	_sign = true;
}

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
	std::cout << "The form " << rhs.getName() << " is " << (rhs.getSign() ? "signed" : "not signed") <<
			  " the grade require to sign it is " << rhs.getSignGrade() << " the grade require to execute it is " <<
			  rhs.getExecGrade();
	return o;
}
