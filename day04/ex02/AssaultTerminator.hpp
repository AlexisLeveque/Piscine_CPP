//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX02_ASSAULTTERMINATOR_HPP
#define EX02_ASSAULTTERMINATOR_HPP


#include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine{

public:
    AssaultTerminator(void);

    AssaultTerminator(AssaultTerminator const &src);

    AssaultTerminator &operator=(AssaultTerminator const &rhs);

    ~AssaultTerminator(void);

    virtual ISpaceMarine* clone() const;
    virtual void battleCry() const;
    virtual void rangedAttack() const;
    virtual void meleeAttack() const;

};


#endif //EX02_ASSAULTTERMINATOR_HPP
