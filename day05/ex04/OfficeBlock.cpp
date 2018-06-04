//
// Created by Alexis LEVEQUE on 6/4/18.
//

#include "OfficeBlock.hpp"

OfficeBlock::OfficeBlock(void) : _intern(nullptr), _exec(nullptr), _sign(nullptr) {}

OfficeBlock::OfficeBlock(Intern &intern, Bureaucrat &bureaucrat1, Bureaucrat &bureaucrat2) : _intern(&intern),
																							 _sign(&bureaucrat1), _exec(&bureaucrat2) {}

OfficeBlock::OfficeBlock(OfficeBlock const &src) {}

OfficeBlock &OfficeBlock::operator=(OfficeBlock const &rhs) {}

OfficeBlock::~OfficeBlock(void) {}

void OfficeBlock::doBureaucracy(std::string form, std::string target) {
	if (_sign && _exec && _intern) {
		Form *newForm;
		newForm = _intern->makeForm(form, target);
		_sign->signForm(*newForm);
		_exec->executeForm(*newForm);
	}
	else {
		throw SomeoneMissingException();
	}
}

void OfficeBlock::setIntern(Intern& intern) {
	_intern = &intern;
}

void OfficeBlock::setSigningBureaucrat(Bureaucrat& bureaucrat) {
	_sign = &bureaucrat;
}

void OfficeBlock::setExecutingBureaucrat(Bureaucrat& bureaucrat) {
	_exec = &bureaucrat;
}
