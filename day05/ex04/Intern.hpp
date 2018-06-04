//
// Created by Alexis LEVEQUE on 6/4/18.
//

#ifndef EX03_INTERN_HPP
#define EX03_INTERN_HPP


#include <iostream>
#include "Form.hpp"

class Intern {

public:
	class NoMatchingFormNameException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return ("No matching form name");
		}
	};

public:
	Intern(void);

	Intern(Intern const &src);

	Intern &operator=(Intern const &rhs);

	~Intern(void);

	Form *makeForm(std::string&, std::string&);
};


#endif //EX03_INTERN_HPP
