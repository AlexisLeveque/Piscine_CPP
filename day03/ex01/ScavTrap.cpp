//
// Created by Alexis LEVEQUE on 5/31/18.
//

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string &name) : _MaxHitPoints(100), _MaxEnergyPoints(50), _HitPoints(100),  _EnergyPoints(50),
                                      _Level(1), _Name(name), _MeleeAttackDamage(20), _RangedAttackDamage(15), _ArmorDamageReduction(3) {
    std::cout << "ScavTrap is up" << std::endl;
    srand (time(nullptr));
}

ScavTrap::ScavTrap(ScavTrap const &src) : _MaxHitPoints(src.getMaxHitPoints()), _MaxEnergyPoints(src.getMaxEnergyPoints()),
                                       _HitPoints(src.getHitpoints()),  _EnergyPoints(src.getEnergyPoints()),  _Level(src.getLevel()),
                                       _Name(src.getName()), _MeleeAttackDamage(src.getMeleeAttackDamage()), _RangedAttackDamage(src.getRangedAttackDamage()),
                                       _ArmorDamageReduction(src.getArmorDamageReduction()) {
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {
    this->setHitPoints(rhs.getHitpoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setLevel(rhs.getLevel());
    this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    return *this;
}

ScavTrap::~ScavTrap(void) {
    std::cout << "Bye good old world!" << std::endl;
}

void ScavTrap::rangedAttack(std::string const &target) {
    std::cout << this->getName() <<
              " throw a projectile to " << target << " looks like it hurts: " << target << " take " << this->getRangedAttackDamage()
              << "points of damage !" << std::endl;
}

void ScavTrap::meleeAttack(std::string const &target) {
    std::cout << this->getName() <<
              " rushes on " << target << " looks like it hurts: " << target << " take " << this->getMeleeAttackDamage()
              << "points of damage !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
    int damage;
    if (amount <= (unsigned int)this->getArmorDamageReduction())
        damage = 0;
    else
        damage = amount - this->getArmorDamageReduction();
    setHitPoints(this->getHitpoints() - damage);
    std::cout << this->getName() << " take " << damage << " point of damage, that hurts!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
    setHitPoints(this->getHitpoints() + amount);

    std::cout << this->getName() << " gets " << amount << " heal points, he now have " << this->getHitpoints() << " HP !" << std::endl;

}

void ScavTrap::challengeNewcomer() {
    void (ScavTrap::*challenge[])(void) = {&ScavTrap::laser, &ScavTrap::fly, &ScavTrap::duckThrow,
                                                            &ScavTrap::trap, &ScavTrap::run};

    (this->*challenge[rand() % 5])();
}

void ScavTrap::laser() {
    std::cout << "Try to hit the apple on my head with your laser gun" << std::endl;
}

void ScavTrap::fly() {
    std::cout << "Catch a fly" << std::endl;
}

void ScavTrap::duckThrow() {
    std::cout << "Find a duck and throw it as far as possible (poor duck)" << std::endl;
}

void ScavTrap::trap() {
    std::cout << "Walk on a trap without active it good luck!" << std::endl;
    this->setHitPoints(this->getHitpoints() - 10);
}

void ScavTrap::run() {
    std::cout << "Run as far as you can (Bye!)" << std::endl;
}

int ScavTrap::getHitpoints() const {
    return this->_HitPoints;
}

int ScavTrap::getMaxHitPoints() const {
    return this->_MaxHitPoints;
}

int ScavTrap::getEnergyPoints() const {
    return this->_EnergyPoints;
}

int ScavTrap::getMaxEnergyPoints() const {
    return this->_MaxEnergyPoints;
}

int ScavTrap::getLevel() const {
    return this->_Level;
}

std::string ScavTrap::getName() const {
    return this->_Name;
}

int ScavTrap::getMeleeAttackDamage() const {
    return this->_MeleeAttackDamage;
}

int ScavTrap::getRangedAttackDamage() const {
    return this->_RangedAttackDamage;
}

int ScavTrap::getArmorDamageReduction() const {
    return this->_ArmorDamageReduction;
}

void ScavTrap::setHitPoints(int nbr) {
    if (nbr > this->getMaxHitPoints())
        this->_HitPoints = this->getMaxHitPoints();
    else if (nbr < 0)
        this->_HitPoints = 0;
    else
        this->_HitPoints = nbr;
}

void ScavTrap::setEnergyPoints(int nbr) {
    if (nbr > this->getMaxEnergyPoints())
        this->_EnergyPoints = this->getMaxEnergyPoints();
    else if (nbr < 0)
        this->_EnergyPoints = 0;
    else
        this->_EnergyPoints = nbr;
}

void ScavTrap::setMaxHitPoints(int nbr) {
    this->_MaxHitPoints = nbr;
}

void ScavTrap::setMaxEnergyPoints(int nbr) {
    this->_MaxEnergyPoints = nbr;
}

void ScavTrap::setLevel(int nbr) {
    this->_Level = nbr;
}

void ScavTrap::setMeleeAttackDamage(int nbr) {
    this->_MeleeAttackDamage = nbr;
}

void ScavTrap::setRangedAttackDamage(int nbr) {
    this->_RangedAttackDamage = nbr;
}

void ScavTrap::setArmorDamageReduction(int nbr) {
    this->_ArmorDamageReduction = nbr;
}