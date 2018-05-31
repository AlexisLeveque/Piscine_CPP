//
// Created by Alexis LEVEQUE on 5/31/18.
//

#include <iostream>
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {}

ScavTrap::ScavTrap(std::string &name) {
    this->setHitPoints(100);
    this->setMaxHitPoints(100);
    this->setEnergyPoints(50);
    this->setMaxEnergyPoints(50);
    this->setLevel(1);
    this->setName(name);
    this->setMeleeAttackDamage(20);
    this->setRangedAttackDamage(15);
    this->setArmorDamageReduction(3);
    std::cout << "ScavTrap is up" << std::endl;
    srand (time(nullptr));
}

ScavTrap::ScavTrap(ScavTrap const &src) {
    this->setHitPoints(src.getHitpoints());
    this->setMaxHitPoints(src.getMaxEnergyPoints());
    this->setEnergyPoints(src.getEnergyPoints());
    this->setMaxEnergyPoints(src.getMaxEnergyPoints());
    this->setLevel(src.getLevel());
    this->setName(src.getName());
    this->setMeleeAttackDamage(src.getMeleeAttackDamage());
    this->setRangedAttackDamage(src.getRangedAttackDamage());
    this->setArmorDamageReduction(src.getArmorDamageReduction());
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



void ScavTrap::challengeNewcomer() {
    void (ScavTrap::*challenge[])() = {&ScavTrap::laser, &ScavTrap::fly, &ScavTrap::duckThrow,
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
