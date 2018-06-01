//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX01_AWEAPON_HPP
#define EX01_AWEAPON_HPP

#import <iostream>

class AWeapon {

public:
    AWeapon(std::string const& name, int apcost, int damage);

    AWeapon(AWeapon const &src);

    AWeapon &operator=(AWeapon const &rhs);

    virtual ~AWeapon(void);

    std::string const getName() const;
    int getAPCost() const;
    int getDamage() const;
    virtual void attack() const = 0;

private:
    AWeapon(void);
    std::string _name;
    int _apCost;
    int _damage;


};


#endif //EX01_AWEAPON_HPP
