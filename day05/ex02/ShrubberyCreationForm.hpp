//
// Created by Alexis LEVEQUE on 6/4/18.
//

#ifndef EX02_SHRUBBERYCREATIONFORM_HPP
#define EX02_SHRUBBERYCREATIONFORM_HPP


#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class ShrubberyCreationForm : public Form {

public:
	ShrubberyCreationForm(void);

	ShrubberyCreationForm(std::string);

	ShrubberyCreationForm(ShrubberyCreationForm const &src);

	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &rhs);

	virtual ~ShrubberyCreationForm(void);

	std::string		getTarget() const ;

	virtual void execute(Bureaucrat const & executor) const;

private:
	std::string _target;
};


#endif //EX02_SHRUBBERYCREATIONFORM_HPP
