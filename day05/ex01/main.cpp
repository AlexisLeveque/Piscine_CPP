#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main() {
	Form	impots("Impots", 130, 10);
	Form	inscription("Inscription", 130, 10);
	Bureaucrat thierry("Thierry", 140);
	Bureaucrat jhon("Jhon", 120);
	try {
		std::cout << impots << std::endl;
		impots.beSigned(thierry);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << impots << std::endl;
	impots.beSigned(jhon);
	std::cout << impots << std::endl;
	std::cout << inscription << std::endl;
	thierry.signForm(inscription);
	std::cout << inscription << std::endl;
	jhon.signForm(inscription);
	std::cout << inscription << std::endl;
	jhon.signForm(inscription);

}