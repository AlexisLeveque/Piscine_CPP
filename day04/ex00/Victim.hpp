//
// Created by PC on 01/06/2018.
//

#ifndef EX00_VICTIM_HPP
#define EX00_VICTIM_HPP

#import <iostream>

class Victim {

public:
    Victim(std::string name);
    ~Victim(void);
    Victim(Victim const& copy);
    Victim &operator=(Victim const &rhs);

    std::string getName() const;

    virtual void polymorph(Victim const&victim) const;


private:
    std::string _name;

protected:
    Victim(void);

};

std::ostream & operator<<( std::ostream & o, Victim const & rhs );


#endif //EX00_VICTIM_HPP
