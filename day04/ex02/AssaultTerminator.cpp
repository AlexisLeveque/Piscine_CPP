//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include <iostream>
#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator(void) {
    std::cout << "* teleports from space *" << std::endl;

}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) {
    *this = src;
}

AssaultTerminator &AssaultTerminator::operator=(AssaultTerminator const &rhs) {
    (void)rhs;
    return *this;
}

AssaultTerminator::~AssaultTerminator(void) {
    std::cout << "I’ll be back ..." << std::endl;

}

ISpaceMarine* AssaultTerminator::clone() const {
    return new AssaultTerminator();

}

void AssaultTerminator::battleCry() const {
    std::cout << "This code is unclean. PURIFY IT !" << std::endl;

}

void AssaultTerminator::rangedAttack() const {
    std::cout << "* does nothing *" << std::endl;

}

void AssaultTerminator::meleeAttack() const {
    std::cout << "* attacks with chainfists *" << std::endl;

}
