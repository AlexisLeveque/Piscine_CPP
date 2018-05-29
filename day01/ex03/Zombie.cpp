//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie(){}

Zombie::~Zombie() {}

void Zombie::announce() const {
    std::cout << _name << " (" << _type << ") > Braiiiiiiinnnssss..." << std::endl;
}

void Zombie::setName(std::string str) {
    this->_name = str;
}

void Zombie::setType(std::string str) {
    this->_type = str;
}