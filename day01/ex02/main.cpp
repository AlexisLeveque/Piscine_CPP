//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <time.h>


void    randomChump(ZombieEvent event) {
    std::string names[10] = {"Esteban", "Ethyl", "Keeley", "Brian", "Tiffiny", "Kelsie", "Jessica", "Emery", "Waylon", "Francesca"};
    Zombie * newOne;
    newOne = event.newZombie(names[rand() % 10]);
    newOne->announce();
    delete newOne;
}


int     main() {
    ZombieEvent dead;
    dead.setZombieType( std::string("dead") );
    srand (time(0));
    Zombie *zombie;

    for (int x = 0; x < 5; ++x) {
        randomChump(dead);
    }
    dead.setZombieType( std::string("less dead") );
    zombie = dead.newZombie("Jimmy");
    zombie->announce();
    delete zombie;

    return 0;
}