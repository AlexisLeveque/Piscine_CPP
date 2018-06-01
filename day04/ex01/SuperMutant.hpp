//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX01_SUPERMUTANT_HPP
#define EX01_SUPERMUTANT_HPP


#include "Enemy.hpp"

class SuperMutant : public Enemy{

public:
    SuperMutant(void);

    SuperMutant(SuperMutant const &src);

    SuperMutant &operator=(SuperMutant const &rhs);

    virtual ~SuperMutant(void);

    virtual void takeDamage(int nbr);


};


#endif //EX01_SUPERMUTANT_HPP
