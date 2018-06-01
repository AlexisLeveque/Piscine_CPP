//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(void) : Enemy(80, "RadScorpion"){
    std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const &src) : Enemy(src.getHP(), src.getType()) {}

RadScorpion &RadScorpion::operator=(RadScorpion const &rhs) {
    Enemy::operator=(rhs);
    return *this;
}

RadScorpion::~RadScorpion(void) {
    std::cout << "* SPROTCH *" << std::endl;
}