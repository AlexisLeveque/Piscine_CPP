//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX03_ICE_HPP
#define EX03_ICE_HPP


#include "AMateria.hpp"
#import "ICharacter.hpp"


class Ice : public AMateria {

public:
    Ice(void);

    Ice(Ice const &src);

    Ice &operator=(Ice const &rhs);

    ~Ice(void);

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);


};


#endif //EX03_ICE_HPP
