//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "Enemy.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(int hp, std::string const &type) : _type(type), _hitPoints(hp) {}

Enemy::Enemy(Enemy const &src) : _type(src.getType()), _hitPoints(src.getHP())  {}

Enemy &Enemy::operator=(Enemy const &rhs) {
    this->_type = rhs.getType();
    this->_hitPoints = rhs.getHP();
    return *this;
}

Enemy::~Enemy(void) {}

int Enemy::getHP() const {
    return this->_hitPoints;
}

std::string const Enemy::getType() const {
    return this->_type;
}

void Enemy::takeDamage(int nbr) {
    if (nbr > 0)
        this->setHP(this->getHP() - nbr);
}

void Enemy::setHP(int nbr) {
    if (nbr < 0)
        this->_hitPoints = 0;
    else
        this->_hitPoints = nbr;
}