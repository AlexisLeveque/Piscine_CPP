//
// Created by Alexis LEVEQUE on 5/31/18.
//

#ifndef EX01_CLAPTRAP_HPP
#define EX01_CLAPTRAP_HPP


#include <iostream>

class ClapTrap {

public:
    ClapTrap(void);

    ClapTrap(ClapTrap const &src);

    ClapTrap &operator=(ClapTrap const &rhs);

    ~ClapTrap(void);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

    void    setHitPoints(int nbr);
    void    setEnergyPoints(int nbr);
    void    setMaxHitPoints(int nbr);
    void    setMaxEnergyPoints(int nbr);
    void    setLevel(int nbr);
    void    setName(std::string name);
    void    setMeleeAttackDamage(int nbr);
    void    setRangedAttackDamage(int nbr);
    void    setArmorDamageReduction(int nbr);
    int     getHitpoints() const ;
    int     getEnergyPoints() const ;
    int     getMaxHitPoints() const ;
    int     getMaxEnergyPoints() const ;
    int     getLevel() const ;
    std::string getName() const ;
    int     getMeleeAttackDamage() const ;
    int     getRangedAttackDamage() const ;
    int     getArmorDamageReduction() const ;


protected:
    int _MaxHitPoints;
    int _MaxEnergyPoints;
    int _HitPoints;
    int _EnergyPoints;
    int _Level;
    std::string _Name;
    int _MeleeAttackDamage;
    int _RangedAttackDamage;
    int _ArmorDamageReduction;

};


#endif //EX01_CLAPTRAP_HPP
