//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include <string>
#include "Human.hpp"

Human::Human() {}


Human::~Human() {}


std::string Human::identify() {
    return _brain.identify();
}


Brain& Human::getBrain() {
    Brain& brain = _brain;
    return brain;
}