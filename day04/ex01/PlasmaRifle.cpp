//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) {}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) : AWeapon(src){}

PlasmaRifle &PlasmaRifle::operator=(PlasmaRifle const &rhs) {
    AWeapon::operator=(rhs);
    return *this;
}

PlasmaRifle::~PlasmaRifle(void) {}

void PlasmaRifle::attack() const {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}