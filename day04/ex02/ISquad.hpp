//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX02_ISQUAD_HPP
#define EX02_ISQUAD_HPP

#include "ISpaceMarine.hpp"

class ISquad
{
public:
    virtual ~ISquad() {}
    virtual int getCount() const = 0;
    virtual ISpaceMarine* getUnit(int) const = 0;
    virtual int push(ISpaceMarine*) = 0;
};

#endif //EX02_ISQUAD_HPP
