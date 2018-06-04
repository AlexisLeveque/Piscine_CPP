//
// Created by Alexis LEVEQUE on 6/4/18.
//

#ifndef EX04_OFFICEBLOCK_HPP
#define EX04_OFFICEBLOCK_HPP

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"

class OfficeBlock {

public:
	class  SomeoneMissingException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("Someone is missing in the block");
		}
	};

public:
	OfficeBlock(void);

	OfficeBlock(Intern&, Bureaucrat&, Bureaucrat&);

	~OfficeBlock(void);

	void	doBureaucracy(std::string, std::string);

	void	setIntern(Intern&);
	void	setSigningBureaucrat(Bureaucrat&);
	void	setExecutingBureaucrat(Bureaucrat&);


private:
	OfficeBlock(OfficeBlock const &src);
	OfficeBlock &operator=(OfficeBlock const &rhs);

	Intern		*_intern;
	Bureaucrat	*_sign;
	Bureaucrat	*_exec;
};


#endif //EX04_OFFICEBLOCK_HPP
