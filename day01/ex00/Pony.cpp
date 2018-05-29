//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include "Pony.hpp"
#include <iostream>


Pony::Pony(int  height ) : _height(height) {
    std::cout << "A " << _height << "cm Pony is born " << std::endl;
}

Pony::~Pony() {
    std::cout << "A " << _height << "cm Pony died " << std::endl;
}

void Pony::run() const {
    std::cout << "Pony run away ..."<< std::endl;
}

void Pony::setHeight(int height) {
    this->_height = height;
    return;
}

int Pony::getHeight() {
    return this->_height;
}