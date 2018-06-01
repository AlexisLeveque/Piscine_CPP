//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {}

Ice::Ice(Ice const &src) : AMateria("ice") {
    this->_xp = src.getXP();
}

Ice &Ice::operator=(Ice const &rhs) {
    this->_xp = rhs.getXP();
}

Ice::~Ice(void) {}

void Ice::use(ICharacter &target) {
    std::cout << "* shoots an ice bolt at " << targe.getName() << " *" << std::endl;
    this->increase_xp();
}

AMateria* Ice::clone() const {
    AMateria *newIce(Ice(*this));
    return &newIce;
}