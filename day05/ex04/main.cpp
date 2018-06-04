#include <iostream>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"
#include "Form.hpp"

int main() {
	Intern idiotOne;
	Bureaucrat hermes = Bureaucrat("Hermes Conrad", 5);
	Bureaucrat bob = Bureaucrat("Bobby Bobson", 25);
	OfficeBlock ob;
	ob.setIntern(idiotOne);
	ob.setSigningBureaucrat(bob);
	ob.setExecutingBureaucrat(hermes);
	ob.doBureaucracy("PresidentialPardonForm", "Pigley");
	OfficeBlock test;

	try
	{
		test.doBureaucracy("PresidentialPardonForm", "Pigley");
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

}