//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef DAY01_ZOMBIEHORDE_HPP
#define DAY01_ZOMBIEHORDE_HPP

#import "Zombie.hpp"
#import <iostream>

class ZombieHorde {

public:
    ZombieHorde( int nbr );
    ~ZombieHorde( void );


    void announce( void ) ;

private:
    int _nbr_zombie;
    Zombie *_horde;
};


#endif //DAY01_ZOMBIEHORDE_HPP
