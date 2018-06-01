//
// Created by PC on 01/06/2018.
//

#ifndef EX00_SORCERER_HPP
#define EX00_SORCERER_HPP


#include <iostream>
#include "Victim.hpp"

class Sorcerer {

public:
    Sorcerer(std::string name, std::string title);
    ~Sorcerer(void);
    Sorcerer(Sorcerer const& copy);
    Sorcerer &operator=(Sorcerer const &rhs);

    std::string getName() const;
    std::string getTitle() const;

    void polymorph(Victim const& victim) const;


private:
    std::string _name;
    std::string _title;
    Sorcerer(void);

};

std::ostream & operator<<( std::ostream & o, Sorcerer const & rhs );



#endif //EX00_SORCERER_HPP
