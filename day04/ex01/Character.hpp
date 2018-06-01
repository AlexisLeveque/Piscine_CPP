//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX01_CHARACTER_HPP
#define EX01_CHARACTER_HPP

#import <iostream>
#include "Enemy.hpp"
#include "AWeapon.hpp"

class Character {

public:
    Character(std::string const & name);

    Character(Character const &src);

    Character &operator=(Character const &rhs);

    ~Character(void);

    void recoverAP();

    void equip(AWeapon*);
    void attack(Enemy*);
    std::string const getName() const;

    int getAp() const;
    AWeapon *getWeapon() const;
    void setAp(int nbr);

private:
    Character(void);
    std::string _name;
    int _AP;
    AWeapon* _weapon;

};

std::ostream & operator<<( std::ostream & o, Character const & rhs );

#endif //EX01_CHARACTER_HPP
