//
// Created by Alexis LEVEQUE on 6/4/18.
//

#ifndef EX02_PRESIDENTIALPARDONFORM_HPP
#define EX02_PRESIDENTIALPARDONFORM_HPP


#include "Bureaucrat.hpp"
#include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

	PresidentialPardonForm(std::string);

	PresidentialPardonForm(PresidentialPardonForm const &src);

	PresidentialPardonForm &operator=(PresidentialPardonForm const &rhs);

	virtual ~PresidentialPardonForm(void);

	std::string	getTarget() const ;

	virtual void execute(Bureaucrat const & executor) const;

private:
	PresidentialPardonForm(void);
	std::string _target;
};


#endif //EX02_PRESIDENTIALPARDONFORM_HPP
