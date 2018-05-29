//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef PISCINE_ZOMBIE_HPP
#define PISCINE_ZOMBIE_HPP

#include <iostream>

class Zombie {

public:
    Zombie( void );
    ~Zombie( void );
    void announce( void ) const ;
    void setName(std::string str);
    void setType(std::string str);

private:
    std::string _name;
    std::string _type;

};


#endif //PISCINE_ZOMBIE_HPP
