//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(void) : Enemy(170, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const &src) : Enemy(src.getHP(), src.getType()) {}

SuperMutant &SuperMutant::operator=(SuperMutant const &rhs) {
    Enemy::operator=(rhs);
    return *this;
}

SuperMutant::~SuperMutant(void) {
    std::cout << "Aaargh ..." << std::endl;
}

void SuperMutant::takeDamage(int nbr) {
    Enemy::takeDamage(nbr-3);
}