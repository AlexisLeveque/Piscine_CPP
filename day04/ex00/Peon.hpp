//
// Created by PC on 01/06/2018.
//

#ifndef EX00_PEON_HPP
#define EX00_PEON_HPP


#include <iostream>
#include "Victim.hpp"

class Peon : public Victim {

public:
    Peon(std::string name);
    ~Peon(void);

    virtual void polymorph(Victim const&victim) const;


protected:
    Peon(void);

};


#endif //EX00_PEON_HPP
