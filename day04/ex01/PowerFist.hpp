//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX01_POWERFIST_HPP
#define EX01_POWERFIST_HPP


#include "AWeapon.hpp"

class PowerFist : public AWeapon {

public:
    PowerFist(void);

    PowerFist(PowerFist const &src);

    PowerFist &operator=(PowerFist const &rhs);

    virtual ~PowerFist(void);

    void attack() const;


};


#endif //EX01_POWERFIST_HPP
