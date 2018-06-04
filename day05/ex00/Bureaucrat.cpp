//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include "Bureaucrat.hpp"

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