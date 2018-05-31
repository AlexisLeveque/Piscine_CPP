//
// Created by Alexis LEVEQUE on 5/31/18.
//

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) {
    std::cout << "Trap father is on tha place" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src) : _MaxHitPoints(src.getMaxHitPoints()), _MaxEnergyPoints(src.getMaxEnergyPoints()),
_HitPoints(src.getHitpoints()),  _EnergyPoints(src.getEnergyPoints()),  _Level(src.getLevel()),
_Name(src.getName()), _MeleeAttackDamage(src.getMeleeAttackDamage()), _RangedAttackDamage(src.getRangedAttackDamage()),
_ArmorDamageReduction(src.getArmorDamageReduction()) {

}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {
    this->setHitPoints(rhs.getHitpoints());
    this->setEnergyPoints(rhs.getEnergyPoints());
    this->setLevel(rhs.getLevel());
    this->setMeleeAttackDamage(rhs.getMeleeAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    this->setRangedAttackDamage(rhs.getRangedAttackDamage());
    return *this;
}

ClapTrap::~ClapTrap(void) {
    std::cout << "ClapTrap over" << std::endl;

}

void ClapTrap::takeDamage(unsigned int amount) {
    int damage;
    if (amount <= (unsigned int)this->getArmorDamageReduction())
        damage = 0;
    else
        damage = amount - this->getArmorDamageReduction();
    setHitPoints(this->getHitpoints() - damage);
    std::cout << this->getName() << " take " << damage << " point of damage, that hurts!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    setHitPoints(this->getHitpoints() + amount);

    std::cout << this->getName() << " gets " << amount << " heal points, he now have " << this->getHitpoints() << " HP !" << std::endl;

}

int ClapTrap::getHitpoints() const {
    return this->_HitPoints;
}

int ClapTrap::getMaxHitPoints() const {
    return this->_MaxHitPoints;
}

int ClapTrap::getEnergyPoints() const {
    return this->_EnergyPoints;
}

int ClapTrap::getMaxEnergyPoints() const {
    return this->_MaxEnergyPoints;
}

int ClapTrap::getLevel() const {
    return this->_Level;
}

std::string ClapTrap::getName() const {
    return this->_Name;
}

int ClapTrap::getMeleeAttackDamage() const {
    return this->_MeleeAttackDamage;
}

int ClapTrap::getRangedAttackDamage() const {
    return this->_RangedAttackDamage;
}

int ClapTrap::getArmorDamageReduction() const {
    return this->_ArmorDamageReduction;
}

void ClapTrap::setHitPoints(int nbr) {
    if (nbr > this->getMaxHitPoints())
        this->_HitPoints = this->getMaxHitPoints();
    else if (nbr < 0)
        this->_HitPoints = 0;
    else
        this->_HitPoints = nbr;
}

void ClapTrap::setEnergyPoints(int nbr) {
    if (nbr > this->getMaxEnergyPoints())
        this->_EnergyPoints = this->getMaxEnergyPoints();
    else if (nbr < 0)
        this->_EnergyPoints = 0;
    else
        this->_EnergyPoints = nbr;
}

void ClapTrap::setMaxHitPoints(int nbr) {
    this->_MaxHitPoints = nbr;
}

void ClapTrap::setMaxEnergyPoints(int nbr) {
    this->_MaxEnergyPoints = nbr;
}

void ClapTrap::setLevel(int nbr) {
    this->_Level = nbr;
}

void ClapTrap::setName(std::string name) {
    this->_Name = name;
}

void ClapTrap::setMeleeAttackDamage(int nbr) {
    this->_MeleeAttackDamage = nbr;
}

void ClapTrap::setRangedAttackDamage(int nbr) {
    this->_RangedAttackDamage = nbr;
}

void ClapTrap::setArmorDamageReduction(int nbr) {
    this->_ArmorDamageReduction = nbr;
}