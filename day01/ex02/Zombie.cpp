//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie( std::string name , std::string type ) : _name(name), _type(type){}

Zombie::~Zombie() {}

void Zombie::announce() const {
    std::cout << _name << " (" << _type << ") > Braiiiiiiinnnssss..." << std::endl;
}