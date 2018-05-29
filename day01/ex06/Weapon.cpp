//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon) : _type(weapon) {}

Weapon::~Weapon() {}

void Weapon::setType(std::string str) {
    this->_type = str;
}

const std::string& Weapon::getType() const {
    return this->_type;
}