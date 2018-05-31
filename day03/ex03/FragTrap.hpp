//
// Created by Alexis LEVEQUE on 5/31/18.
//

#ifndef EX00_FRAGTAP_HPP
#define EX00_FRAGTAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTap : public ClapTrap{

public:
    FragTap(std::string &name);

    FragTap(FragTap const &src);

    FragTap &operator=(FragTap const &rhs);

    ~FragTap(void);

    void rangedAttack(std::string const & target);

    void meleeAttack(std::string const & target);

    void vaulthunter_dot_exe(std::string const & target);

    void laser(std::string const & target);
    void duckThrow(std::string const & target);
    void minigun(std::string const & target);
    void trap(std::string const & target);
    void oneShot(std::string const & target);


private:
    FragTap(void);



};


#endif //EX00_FRAGTAP_HPP
