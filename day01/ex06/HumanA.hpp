//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef EX06_HUMANA_HPP
#define EX06_HUMANA_HPP


#include <string>
#include "Weapon.hpp"

class HumanA {

public:
    HumanA( std::string name, Weapon& weapon );
    ~HumanA( void );
    void attack( void ) const;


private:
    std::string const _name;
    Weapon& _weapon;
};


#endif //EX06_HUMANA_HPP
