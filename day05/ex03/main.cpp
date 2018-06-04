#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main() {
	Intern roger;

	std::string test("d");
	std::string target("weather");
	std::string form("RobotomyRequestForm");
	Bureaucrat	jizz("jizz", 1);
	Form		*robo;

	roger.makeForm(test, target);
	robo = roger.makeForm(form, target);
	robo->setSign();
	robo->execute(jizz);
	delete robo;

	return 0;

}