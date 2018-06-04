//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include "../ex02/Bureaucrat.hpp"
#include "../ex02/Form.hpp"


Bureaucrat::Bureaucrat(void) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name) {
	if (grade > 150) {

	}
	else if (grade < 1) {

	}
	else {
		_grade = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()){
	_grade = (src.getGrade());
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
	_grade = (rhs.getGrade());
	return *this;
}

Bureaucrat::~Bureaucrat(void) {}

void Bureaucrat::signForm(Form &form) {
	if (form.getSign()) {
		std::cout << this->_name << " cannot sign " << form.getName() << " bescause it's already signed !" << std::endl;
	}
	else if (form.getSignGrade() < this->getGrade()) {
		std::cout << this->_name << " cannot sign " << form.getName() << " bescause is grade is too low !" << std::endl;
	}
	else {
		form.setSign();
		std::cout << this->_name << " signs " << form.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const &form) {
	try {
		form.execute(*this);
		std::cout << this->getName() << " executes " << form.getName() << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << e.what() << std::endl;
	}

}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::string Bureaucrat::getName() const {
	return _name;
}

void Bureaucrat::incrementGrade() {
	if (_grade -1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	--_grade;
}

void Bureaucrat::decrementGrade() {
	if (_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	++_grade;
}

std::ostream &operator<<(std::ostream &o , Bureaucrat const &rhs) {
	std::cout << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return o;
}