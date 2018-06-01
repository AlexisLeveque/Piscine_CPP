//
// Created by PC on 01/06/2018.
//

#include "Victim.hpp"

Victim::Victim() {}

Victim::Victim(std::string name) : _name(name) {
    std::cout << "Some random victim called " << name << " just  popped !" << std::endl;
}

Victim& Victim::operator=(Victim const &rhs) {
    this->_name = rhs.getName();
    return *this;
}

Victim::Victim(Victim const &copy) : _name(copy.getName()) {
}

std::ostream& operator<<(std::ostream &o, Victim const &rhs) {
    std::cout << "I am " << rhs.getName() << " and I like otters !" << std::endl;
    return o;
}

Victim::~Victim() {
    std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
}

std::string Victim::getName() const {
    return this->_name;
}

void Victim::polymorph(Victim const &victim) const {
    std::cout <<victim.getName() << "  has been turned into a cute little sheep !" << std::endl;
}