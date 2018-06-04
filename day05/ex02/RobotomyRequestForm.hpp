//
// Created by Alexis LEVEQUE on 6/4/18.
//

#ifndef EX02_ROBOTOMYREQUESTFORM_HPP
#define EX02_ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"

class RobotomyRequestForm : public Form{

public :
	RobotomyRequestForm(std::string);

	RobotomyRequestForm(RobotomyRequestForm const &src);

	RobotomyRequestForm &operator=(RobotomyRequestForm const &rhs);

	virtual ~RobotomyRequestForm(void);

	std::string	getTarget() const ;

	virtual void execute(Bureaucrat const & executor) const;

private:
	RobotomyRequestForm(void);
	std::string	_target;

};


#endif //EX02_ROBOTOMYREQUESTFORM_HPP
