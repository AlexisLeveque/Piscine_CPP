//
// Created by Alexis LEVEQUE on 5/31/18.
//

#ifndef EX00_FRAGTAP_HPP
#define EX00_FRAGTAP_HPP

#include <iostream>

class FragTap {

public:
    FragTap(std::string &name);

    FragTap(FragTap const &src);

    FragTap &operator=(FragTap const &rhs);

    ~FragTap(void);

    void rangedAttack(std::string const & target);

    void meleeAttack(std::string const & target);

    void takeDamage(unsigned int amount);

    void beRepaired(unsigned int amount);

    void vaulthunter_dot_exe(std::string const & target);

    void laser(std::string const & target);
    void duckThrow(std::string const & target);
    void minigun(std::string const & target);
    void trap(std::string const & target);
    void oneShot(std::string const & target);

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
    FragTap(void);
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


#endif //EX00_FRAGTAP_HPP
