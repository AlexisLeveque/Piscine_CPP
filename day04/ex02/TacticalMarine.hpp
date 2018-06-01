//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX02_TACTICALMARINE_HPP
#define EX02_TACTICALMARINE_HPP


#include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine {

public:
    TacticalMarine(void);

    TacticalMarine(TacticalMarine const &src);

    TacticalMarine &operator=(TacticalMarine const &rhs);

    virtual ~TacticalMarine(void);

    virtual ISpaceMarine* clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;

};


#endif //EX02_TACTICALMARINE_HPP
