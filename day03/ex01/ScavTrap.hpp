//
// Created by Alexis LEVEQUE on 5/31/18.
//

#ifndef EX00_SCAVTRAP_HPP
#define EX00_SCAVTRAP_HPP


#include <string>

class ScavTrap {

public:
    ScavTrap(std::string &name);

    ScavTrap(ScavTrap const &src);

    ScavTrap &operator=(ScavTrap const &rhs);

    ~ScavTrap(void);

    void rangedAttack(std::string const & target);

    void meleeAttack(std::string const & target);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

    void challengeNewcomer();

    void laser();
    void duckThrow();
    void fly();
    void trap();
    void run();

    void    setHitPoints(int nbr);
    void    setEnergyPoints(int nbr);
    void    setMaxHitPoints(int nbr);
    void    setMaxEnergyPoints(int nbr);
    void    setLevel(int nbr);
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


private:
    ScavTrap(void);
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


#endif //EX00_SCAVTRAP_HPP
