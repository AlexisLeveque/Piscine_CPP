//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Brain.hpp"

Brain::Brain() {}

Brain::~Brain() {}

std::string Brain::identify() {
    std::ostringstream address;
    address << (void const *)this;
    std::string name = address.str();
    return name;
}