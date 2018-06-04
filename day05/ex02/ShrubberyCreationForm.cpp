//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) :Form("ShrubberyCreationForm", 145, 137),
																				   _target(src.getTarget()) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
	_target = rhs.getTarget();
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

std::string ShrubberyCreationForm::getTarget() const {
	return _target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (!this->getSign()) {
		throw FormNotSignedException();
	}
	if (executor.getGrade() > this->getExecGrade()) {
		throw GradeTooLowException();
	}
	std::fstream fs;
	fs.open (_target + "_shrubbery", std::fstream::out);

	fs << "               ,@@@@@@@,\n"
		  "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		  "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		  "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		  "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		  "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		  "   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		  "       |o|        | |         | |\n"
		  "       |.|        | |         | |\n"
		  "  \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_" << std::endl;

	fs.close();
}

