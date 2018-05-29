//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef DAY01_ZOMBIEEVENT_HPP
#define DAY01_ZOMBIEEVENT_HPP

#import "Zombie.hpp"
#import <iostream>

class ZombieEvent {

public:
    ZombieEvent( void );
    ~ZombieEvent( void );
    void setZombieType( std::string type ) ;
    Zombie* newZombie(std::string name);

private:
    std::string _type;

};


#endif //DAY01_ZOMBIEEVENT_HPP
