#include <iostream>
#include "Bureaucrat.hpp"


int main() {
	Bureaucrat jean(std::string("Jean"), 1);
	Bureaucrat pierre(std::string("pierre"), 150);

	std::cout << jean << std::endl;

	try
	{
		jean.decrementGrade();
		std::cout << jean << std::endl;
		jean.incrementGrade();
		std::cout << jean << std::endl;
		jean.incrementGrade();
		std::cout << jean << std::endl;


	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << pierre << std::endl;
		pierre.incrementGrade();
		std::cout << pierre << std::endl;
		pierre.decrementGrade();
		std::cout << pierre << std::endl;
		pierre.decrementGrade();
		std::cout << pierre << std::endl;


	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}