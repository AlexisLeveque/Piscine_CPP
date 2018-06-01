//
// Created by Alexis LEVEQUE on 6/1/18.
//

#ifndef EX01_ENEMY_HPP
#define EX01_ENEMY_HPP

#import <iostream>

class Enemy {

public:

    Enemy(int hp, std::string const & type);

    Enemy(Enemy const &src);

    Enemy &operator=(Enemy const &rhs);

    virtual ~Enemy(void);

    std::string const getType() const;
    int getHP() const;
    void setHP(int nbr);

    virtual void takeDamage(int nbr);

private:
    Enemy(void);
    std::string _type;
    int _hitPoints;

};


#endif //EX01_ENEMY_HPP
