//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "AWeapon.hpp"

AWeapon::AWeapon(void) {}

AWeapon::AWeapon(AWeapon const &src) : _name(src.getName()), _apCost(src.getAPCost()), _damage(src.getDamage()) {}

AWeapon &AWeapon::operator=(AWeapon const &rhs) {
    this->_name = rhs.getName();
    this->_apCost = rhs.getAPCost();
    this->_damage = rhs.getDamage();
    return *this;
}

AWeapon::~AWeapon(void) {}

int AWeapon::getDamage() const {
    return this->_damage;
}

int AWeapon::getAPCost() const {
    return this->_apCost;
}

std::string const AWeapon::getName() const {
    return this->_name;
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage) : _name(name), _apCost(apcost), _damage(damage){}