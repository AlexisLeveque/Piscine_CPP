//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &src) {
	(void)src;
}

Intern &Intern::operator=(Intern const &rhs) {
	(void)rhs;
	return *this;
}

Intern::~Intern(void) {}

Form *Intern::makeForm(std::string & name, std::string & target) {
	if (name == "PresidentialPardonForm") {
		std::cout << "Intern creates PresidentialPardonForm targeted on " << target << std::endl;
		return new PresidentialPardonForm(target);
	}
	else if (name == "RobotomyRequestForm") {
		std::cout << "Intern creates RobotomyRequestForm targeted on " << target << std::endl;
		return new RobotomyRequestForm(target);
	}
	else if (name == "ShrubberyCreationForm") {
		std::cout << "Intern creates ShrubberyCreationForm targeted on " << target << std::endl;
		return new ShrubberyCreationForm(target);
	}
	else {
		throw NoMatchingFormNameException();
	}
}