//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include "RobotomyRequestForm.hpp"
#import "../ex02/Bureaucrat.hpp"
#include <iostream>
#include <time.h>


RobotomyRequestForm::RobotomyRequestForm(void) {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45), _target(target) {
	srand(time(nullptr));
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) :Form("RobotomyRequestForm", 72, 45),
																		  _target(src.getTarget()) {
	srand(time(nullptr));
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
	_target = rhs.getTarget();
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (!this->getSign()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	std::cout << "* some drill noise *" << std::endl;
	if (rand() % 2 == 1) {
		std::cout << "Robotomize failed" << std::endl;
	}
	else {
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	}
}

std::string RobotomyRequestForm::getTarget() const {
	return _target;
}
