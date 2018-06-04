#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
	PresidentialPardonForm 	pres("Pilou");
	ShrubberyCreationForm	shrub("Garden");
	RobotomyRequestForm		robo("Tagada");

	Bureaucrat thierry("Thierry", 140);
	Bureaucrat jhon("Jhon", 1);

	std::cout << pres << std::endl;
	pres.beSigned(jhon);
	shrub.beSigned(jhon);
	robo.beSigned(jhon);
	try {
		pres.execute(thierry);
	}
	catch (std::exception const & e) {
		std::cout << e.what() << std::endl;
	}
	pres.execute(jhon);
	jhon.executeForm(robo);
	jhon.executeForm(shrub);

}