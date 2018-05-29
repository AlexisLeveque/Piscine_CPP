//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef PISCINE_ZOMBIE_HPP
#define PISCINE_ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
    Zombie( std::string name, std::string type );
    ~Zombie( void );
    void announce( void ) const ;

private:
    const std::string _name;
    const std::string _type;

};


#endif //PISCINE_ZOMBIE_HPP
