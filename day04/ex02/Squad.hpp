//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX02_SQUAD_HPP
#define EX02_SQUAD_HPP


#include "ISquad.hpp"

class Squad : public ISquad{

public:
    Squad(void);

    Squad(Squad const &src);

    Squad &operator=(Squad const &rhs);

    virtual ~Squad(void);

    virtual int getCount() const;
    virtual ISpaceMarine* getUnit(int) const;
    virtual int push(ISpaceMarine*);

private:
    ISpaceMarine *_squad[50];
    int _count;



};


#endif //EX02_SQUAD_HPP
