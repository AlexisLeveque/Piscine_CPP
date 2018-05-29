//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef EX06_WEAPON_HPP
#define EX06_WEAPON_HPP


#include <string>

class Weapon {

public:
    Weapon( std::string weapon);
    ~Weapon( void );
    const std::string& getType() const;
    void setType(std::string str);

private:
    std::string _type;
};


#endif //EX06_WEAPON_HPP
