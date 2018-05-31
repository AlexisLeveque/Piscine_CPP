//
// Created by Alexis LEVEQUE on 5/31/18.
//

#ifndef EX00_SCAVTRAP_HPP
#define EX00_SCAVTRAP_HPP


#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{

public:
    ScavTrap(std::string &name);

    ScavTrap(ScavTrap const &src);

    ScavTrap &operator=(ScavTrap const &rhs);

    ~ScavTrap(void);

    void rangedAttack(std::string const & target);

    void meleeAttack(std::string const & target);

    void challengeNewcomer();

    void laser();
    void duckThrow();
    void fly();
    void trap();
    void run();


private:
    ScavTrap(void);




};


#endif //EX00_SCAVTRAP_HPP
