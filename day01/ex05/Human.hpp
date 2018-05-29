//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef EX05_HUMAN_H
#define EX05_HUMAN_H


#include "Brain.hpp"

class Human {

public:
    Human( void );
    ~Human( void );

    std::string identify();
    Brain& getBrain();

private:
    Brain _brain;

};


#endif //EX05_HUMAN_H
