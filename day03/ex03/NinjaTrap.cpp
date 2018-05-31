//
// Created by Alexis LEVEQUE on 5/31/18.
//

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap(void) {}

NinjaTrap::NinjaTrap(std::string &name) {
    this->setHitPoints(60);
    this->setMaxHitPoints(60);
    this->setEnergyPoints(120);
    this->setMaxEnergyPoints(120);
    this->setLevel(1);
    this->setName(name);
    this->setMeleeAttackDamage(60);
    this->setRangedAttackDamage(5);
    this->setArmorDamageReduction(0);
    std::cout << "sshh i'm a ninja." << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const &src) {
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

NinjaTrap &NinjaTrap::operator=(NinjaTrap const &rhs) {
    this->setHitPoints(rhs.getHitpoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setLevel(rhs.getLevel());
    this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    return *this;
}

NinjaTrap::~NinjaTrap(void) {
    std::cout << "No ninjas anymore." << std::endl;
}

void NinjaTrap::rangedAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->getName() <<
              " attacks " << target << " at range, causing " << this->getRangedAttackDamage()
              << "points of damage !" << std::endl;
}

void NinjaTrap::meleeAttack(std::string const &target) {
    std::cout << "FR4G-TP " << this->getName() <<
              " attacks " << target << " at melee, causing " << this->getMeleeAttackDamage()
              << "points of damage !" << std::endl;
}

void NinjaTrap::ninjaShoebox(FragTap &frag) {
    std::cout << "Inspiration.exe a cesser de fonctionner you loose 10 Energie" << std::endl;
    frag.setEnergyPoints(frag.getEnergyPoints() - 10);
}

void NinjaTrap::ninjaShoebox(ScavTrap &scav) {
    std::cout << "Oh you are there " << scav.getName() << " make some thing funny please." << std::endl;

}

void NinjaTrap::ninjaShoebox(ClapTrap &clap) {
    std::cout << "*" << clap.getName() << " found a sign who say :" << std::endl;
    std::cout << "Nothing to see here." << std::endl;

}

void NinjaTrap::ninjaShoebox(NinjaTrap &ninja) {
    std::cout << this->getName() << " and " << ninja.getName() << " enter the battle ground B-But where are they they?." << std::endl;
}
