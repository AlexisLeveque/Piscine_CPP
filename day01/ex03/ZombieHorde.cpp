//
// Created by Alexis LEVEQUE on 5/29/18.
//

#import "ZombieHorde.hpp"
#include <iostream>
#include <time.h>

ZombieHorde::ZombieHorde( int nbr ) : _nbr_zombie(nbr) {
    std::string names[20] = {"Esteban", "Ethyl", "Keeley", "Brian", "Tiffiny", "Kelsie", "Jessica", "Emery", "Waylon", "Francesca",
                             "Ute", "Vanita", "Chiquita", "Chance", "Oren", "Ivan", "Aline", "Lacresha", "Rupert", "Everett"};
    srand (time(nullptr));

    std::cout << "A horde is being formed" << std::endl;

    this->_horde = new Zombie[nbr];

    for (int i = 0; i < nbr; ++i) {
        this->_horde[i].setName(names[rand() % 20]);
        this->_horde[i].setType("undead");

    }
}

ZombieHorde::~ZombieHorde() {
    std::cout << "Killing the whole horde" << std::endl;
    delete [] this->_horde;
}

void ZombieHorde::announce() {
    for (int i = 0; i < this->_nbr_zombie; ++i) {
        this->_horde[i].announce();
    }
}


