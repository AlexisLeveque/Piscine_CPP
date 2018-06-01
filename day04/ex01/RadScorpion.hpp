//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX01_RADSCORPION_HPP
#define EX01_RADSCORPION_HPP


#include "Enemy.hpp"

class RadScorpion : public Enemy {

public:
    RadScorpion(void);

    RadScorpion(RadScorpion const &src);

    RadScorpion &operator=(RadScorpion const &rhs);

    virtual ~RadScorpion(void);

};


#endif //EX01_RADSCORPION_HPP
