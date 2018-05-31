//
// Created by Alexis LEVEQUE on 5/31/18.
//

#ifndef EX03_NINJATRAP_HPP
#define EX03_NINJATRAP_HPP


#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap {

public:
    NinjaTrap(std::string &name);

    NinjaTrap(NinjaTrap const &src);

    NinjaTrap &operator=(NinjaTrap const &rhs);

    ~NinjaTrap(void);

    void rangedAttack(std::string const & target);

    void meleeAttack(std::string const & target);

    void ninjaShoebox(NinjaTrap &ninja);
    void ninjaShoebox(ClapTrap &clap);
    void ninjaShoebox(ScavTrap &scav);
    void ninjaShoebox(FragTap &frag);



private:
    NinjaTrap(void);
};


#endif //EX03_NINJATRAP_HPP
