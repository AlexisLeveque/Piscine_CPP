//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef EX06_HUMANB_HPP
#define EX06_HUMANB_HPP


#include "Weapon.hpp"

class HumanB {

public:
    HumanB( std::string name );
    ~HumanB( void );

    void setWeapon(Weapon& weapon);
    void attack( void ) const;



private:
    std::string const _name;
    Weapon* _weapon;
};


#endif //EX06_HUMANB_HPP
