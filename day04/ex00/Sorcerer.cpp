//
// Created by PC on 01/06/2018.
//

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() {}

Sorcerer::Sorcerer(std::string name, std::string title) : _name(name), _title(title){
    std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer& Sorcerer::operator=(Sorcerer const &rhs) {
    this->_name = rhs.getName();
    this->_title = rhs.getTitle();
    return *this;
}

Sorcerer::Sorcerer(Sorcerer const &copy) {
    this->_name = copy.getName();
    this->_title = copy.getTitle();
}

std::ostream& operator<<(std::ostream &o, Sorcerer const &rhs) {
    std::cout << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
    return o;
}

Sorcerer::~Sorcerer() {
    std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
}

void Sorcerer::polymorph(Victim const &victim) const {
    victim.polymorph(victim);
}

std::string Sorcerer::getName() const {
    return this->_name;
}

std::string Sorcerer::getTitle() const {
    return this->_title;
}