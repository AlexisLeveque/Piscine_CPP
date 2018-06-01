//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) {}

PowerFist::PowerFist(PowerFist const &src) : AWeapon(src){}

PowerFist &PowerFist::operator=(PowerFist const &rhs) {
    AWeapon::operator=(rhs);
    return *this;
}

PowerFist::~PowerFist(void) {}

void PowerFist::attack() const {
    std::cout << "*pschhh... SBAM! *" << std::endl;
}