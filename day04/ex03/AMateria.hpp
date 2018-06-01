//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX03_AMATERIA_HPP
#define EX03_AMATERIA_HPP

#import <iostream>
#import "ICharacter.hpp"

class AMateria {

public:
    AMateria(std::string const & type);

    AMateria(AMateria const &src);

    AMateria &operator=(AMateria const &rhs);

    virtual ~AMateria(void);

    unsigned int getXP() const; //Returns the Materia's XP

    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
    void increase_xp();

private:
    AMateria(void);
    std::string _type;

protected:
    unsigned int _xp;

};


#endif //EX03_AMATERIA_HPP
