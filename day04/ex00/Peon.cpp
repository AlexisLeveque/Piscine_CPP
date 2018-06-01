//
// Created by PC on 01/06/2018.
//

#include "Peon.hpp"

Peon::Peon() {}

Peon::Peon(std::string name) : Victim(name) {
    std::cout << "Zog zog." << std::endl;
}

Peon::~Peon() {
    std::cout << "Bleuark..." << std::endl;
}

void Peon::polymorph(Victim const &victim) const {
    std::cout << victim.getName() << "  has been turned into a pink pony !" << std::endl;
}