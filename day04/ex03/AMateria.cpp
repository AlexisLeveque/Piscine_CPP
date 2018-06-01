//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "AMateria.hpp"

AMateria::AMateria(void) {}

AMateria::AMateria(std::string const &type) : _xp(0), _type(type) {}

AMateria::AMateria(AMateria const &src) : _xp(src.getXP()) {}

AMateria &AMateria::operator=(AMateria const &rhs) {
    this->_xp = rhs.getXP();
}

AMateria::~AMateria(void) {}

unsigned int AMateria::getXP() const {
    return this->_xp;
}

void AMateria::increase_xp() {
    this->_xp += 10;
}