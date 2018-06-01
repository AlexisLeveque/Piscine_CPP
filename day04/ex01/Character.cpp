//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "Character.hpp"

Character::Character(void) {}

Character::Character(std::string const& name) : _name(name), _AP(40), _weapon(nullptr){}

Character::Character(Character const &src) : _name(src.getName()), _AP(src.getAp()), _weapon(src.getWeapon()) {}

Character &Character::operator=(Character const &rhs) {
    this->_AP = rhs.getAp();
    this->_weapon = rhs.getWeapon();
    this->_name = rhs.getName();
    return *this;
}

Character::~Character(void) {}


void Character::attack(Enemy *enemy) {
    AWeapon* weapon = this->getWeapon();
    if (weapon && this->getAp() >= weapon->getAPCost()) {
        std::cout << this->getName() << " attacks " << enemy->getType() << " with a " << weapon->getName()
                  << std::endl;
        weapon->attack();
        this->setAp(this->getAp() - weapon->getAPCost());
        enemy->setHP(enemy->getHP() - weapon->getDamage());
        if (enemy->getHP() == 0)
            delete enemy;
    }

}

void Character::equip(AWeapon *weapon) {
    this->_weapon = weapon;
}

void Character::recoverAP() {
    this->setAp(this->getAp() + 10);
}

int Character::getAp() const {
    return this->_AP;
}

std::string const Character::getName() const {
    return this->_name;
}
AWeapon* Character::getWeapon() const {
    return this->_weapon;
}

void Character::setAp(int nbr) {
    if (nbr > 40)
        this->_AP = 40;
    else if (nbr < 0)
        this->_AP = 0;
    else
        this->_AP = nbr;
}

std::ostream& operator<<(std::ostream &o, Character const &rhs) {
    if (rhs.getWeapon())
        std::cout << rhs.getName() << " has " << rhs.getAp() << " AP and wields a " << rhs.getWeapon()->getName() << std::endl;
    else
        std::cout << rhs.getName() << " has " << rhs.getAp() << " AP and is unarmed" << std::endl;
    return o;
}