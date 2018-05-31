//
// Created by Alexis LEVEQUE on 5/31/18.
//

#include <iostream>
#include <time.h>
#include "FragTrap.hpp"

FragTap::FragTap() {}

FragTap::FragTap(std::string &name) {
    this->setHitPoints(100);
    this->setMaxHitPoints(100);
    this->setEnergyPoints(100);
    this->setMaxEnergyPoints(100);
    this->setLevel(1);
    this->setName(name);
    this->setMeleeAttackDamage(30);
    this->setRangedAttackDamage(20);
    this->setArmorDamageReduction(5);
    std::cout << "start bootup sequence." << std::endl;
    srand (time(nullptr));
}

FragTap::FragTap(FragTap const &src) {
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
