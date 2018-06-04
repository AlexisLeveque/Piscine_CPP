//
// Created by Alexis LEVEQUE on 6/2/18.
//

#include "Element.hpp"

#ifndef FT_RETRO_ENEMY_HPP
#define FT_RETRO_ENEMY_HPP


class Enemy : public Element {

public:


	Enemy(char character, int fireRate, int moveRate, int x, int y);

	Enemy(Enemy const &src);

	Enemy &operator=(Enemy const &rhs);

	~Enemy(void);

	int getFireRate() const;
	int getMoveRate() const;
	int incrementFire();
	int incrementMove();


private:
	Enemy(void);
	int _fireRate;
	int _moveRate;
	int _fire;
	int _move;

};


#endif //FT_RETRO_ENEMY_HPP
