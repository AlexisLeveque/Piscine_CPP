//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) :Form("PresidentialPardonForm", 25, 5),
																		  _target(src.getTarget()) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
	_target = rhs.getTarget();
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

std::string PresidentialPardonForm::getTarget() const {
	return _target;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (!this->getSign()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}