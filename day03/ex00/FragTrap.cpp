//
// Created by Alexis LEVEQUE on 5/31/18.
//

#include <iostream>
#include <time.h>
#include "FragTrap.hpp"


FragTap::FragTap() {}
FragTap::FragTap(std::string &name) : _MaxHitPoints(100), _MaxEnergyPoints(100), _HitPoints(100),  _EnergyPoints(100),
                    _Level(1), _Name(name), _MeleeAttackDamage(30), _RangedAttackDamage(20), _ArmorDamageReduction(5) {
    std::cout << "start bootup sequence." << std::endl;

}

FragTap::FragTap(FragTap const &src) : _MaxHitPoints(src.getMaxHitPoints()), _MaxEnergyPoints(src.getMaxEnergyPoints()),
                   _HitPoints(src.getHitpoints()),  _EnergyPoints(src.getEnergyPoints()),  _Level(src.getLevel()),
                   _Name(src.getName()), _MeleeAttackDamage(src.getMeleeAttackDamage()), _RangedAttackDamage(src.getRangedAttackDamage()),
                   _ArmorDamageReduction(src.getArmorDamageReduction()) {
}

FragTap &FragTap::operator=(FragTap const &rhs) {
    this->setHitPoints(rhs.getHitpoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setLevel(rhs.getLevel());
    this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    return *this;
}

FragTap::~FragTap(void) {
    std::cout << "I'M DEAD I'M DEAD OHMYGOD I'M DEAD!" << std::endl;
}

void FragTap::rangedAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->getName() <<
              " attacks " << target << " at range, causing " << this->getRangedAttackDamage()
              << "points of damage !" << std::endl;
}

void FragTap::meleeAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->getName() <<
              " attacks " << target << " at melee, causing " << this->getMeleeAttackDamage()
              << "points of damage !" << std::endl;
}

void FragTap::takeDamage(unsigned int amount) {
    int damage;
    if (amount <= (unsigned int)this->getArmorDamageReduction())
        damage = 0;
    else
        damage = amount - this->getArmorDamageReduction();
    setHitPoints(this->getHitpoints() - damage);
    std::cout << this->getName() << " take " << damage << " point of damage, that hurts!" << std::endl;
}

void FragTap::beRepaired(unsigned int amount) {
    setHitPoints(this->getHitpoints() + amount);

    std::cout << this->getName() << " gets " << amount << " heal points, he now have " << this->getHitpoints() << " HP !" << std::endl;

}

void FragTap::vaulthunter_dot_exe(std::string const &target) {
    void (FragTap::*attack[])(std::string const &target) = {&FragTap::laser, &FragTap::minigun, &FragTap::duckThrow,
                                                            &FragTap::trap, &FragTap::oneShot};
    srand (time(nullptr) + rand());
    if (this->getEnergyPoints() < 25)
        std::cout << "You don't have enough Energy" << std::endl;
    else {
        this->setEnergyPoints(this->getEnergyPoints() - 25);
        (this->*attack[rand() % 5])(target);

    }
}

void FragTap::laser(std::string const &target) {
    std::cout << "You attack " << target <<  " with laser blaster pew pew" << std::endl;
}

void FragTap::minigun(std::string const &target) {
    std::cout << "You attack " << target <<  " with a minigun ratatatatatatattatatatatatata" << std::endl;
}

void FragTap::duckThrow(std::string const &target) {
    std::cout << "You throw duck to " << target << " coin coin" << std::endl;
}

void FragTap::trap(std::string const &target) {
    std::cout << "it's a trap you loose 10HP " << target <<  " laughed" << std::endl;
    this->setHitPoints(this->getHitpoints() - 10);
}

void FragTap::oneShot(std::string const &target) {
    std::cout << "You've one shoted " << target << " with class" << std::endl;
}

int FragTap::getHitpoints() const {
    return this->_HitPoints;
}

int FragTap::getMaxHitPoints() const {
    return this->_MaxHitPoints;
}

int FragTap::getEnergyPoints() const {
    return this->_EnergyPoints;
}

int FragTap::getMaxEnergyPoints() const {
    return this->_MaxEnergyPoints;
}

int FragTap::getLevel() const {
    return this->_Level;
}

std::string FragTap::getName() const {
    return this->_Name;
}

int FragTap::getMeleeAttackDamage() const {
    return this->_MeleeAttackDamage;
}

int FragTap::getRangedAttackDamage() const {
    return this->_RangedAttackDamage;
}

int FragTap::getArmorDamageReduction() const {
    return this->_ArmorDamageReduction;
}

void FragTap::setHitPoints(int nbr) {
    if (nbr > this->getMaxHitPoints())
        this->_HitPoints = this->getMaxHitPoints();
    else if (nbr < 0)
        this->_HitPoints = 0;
    else
        this->_HitPoints = nbr;
}

void FragTap::setEnergyPoints(int nbr) {
    if (nbr > this->getMaxEnergyPoints())
        this->_EnergyPoints = this->getMaxEnergyPoints();
    else if (nbr < 0)
        this->_EnergyPoints = 0;
    else
        this->_EnergyPoints = nbr;
}

void FragTap::setLevel(int nbr) {
    this->_Level = nbr;
}

void FragTap::setMeleeAttackDamage(int nbr) {
    this->_MeleeAttackDamage = nbr;
}

void FragTap::setRangedAttackDamage(int nbr) {
    this->_RangedAttackDamage = nbr;
}

void FragTap::setArmorDamageReduction(int nbr) {
    this->_ArmorDamageReduction = nbr;
}