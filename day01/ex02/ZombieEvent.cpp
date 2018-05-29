//
// Created by Alexis LEVEQUE on 5/29/18.
//

#import "ZombieEvent.hpp"


ZombieEvent::ZombieEvent() {}

ZombieEvent::~ZombieEvent() {}

void ZombieEvent::setZombieType(std::string type) {
    this->_type = type;
}

Zombie* ZombieEvent::newZombie(std::string name) {
    return new Zombie(name, _type);
}