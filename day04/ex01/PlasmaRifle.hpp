//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX01_PLASMARIFLE_HPP
#define EX01_PLASMARIFLE_HPP


#include "AWeapon.hpp"

class PlasmaRifle : public AWeapon {

public:
    PlasmaRifle(void);

    PlasmaRifle(PlasmaRifle const &src);

    PlasmaRifle &operator=(PlasmaRifle const &rhs);

    virtual ~PlasmaRifle(void);

    void attack() const;

};


#endif //EX01_PLASMARIFLE_HPP
