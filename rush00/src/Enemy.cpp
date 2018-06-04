//
// Created by Alexis LEVEQUE on 6/2/18.
//

#include "Enemy.hpp"
#include "Log.hpp"
#include "ft_retro.hpp"

Enemy::Enemy(void) {}

Enemy::Enemy(char character, int fireRate, int moveRate, int x, int y) : Element(ENEMY, character), _fireRate(fireRate),
																		 _moveRate(moveRate), _fire(0), _move(0){
	log << __PRETTY_FUNCTION__ << std::endl;
	this->setCoordX(x);
	this->setCoordY(y);

}

Enemy::Enemy(Enemy const &src) : Element(ENEMY, src.getCharacter()), _fireRate(src.getFireRate())
		, _moveRate(src.getMoveRate()) {
	log << __PRETTY_FUNCTION__ << std::endl;
	this->setCoordX(src.getCoordX());
	this->setCoordY(src.getCoordY());

}

Enemy &Enemy::operator=(Enemy const &rhs) {
	log << __PRETTY_FUNCTION__ << std::endl;

	this->_fireRate = rhs.getFireRate();
	this->_moveRate = rhs.getMoveRate();
	return *this;
}

Enemy::~Enemy(void) {
	log << __PRETTY_FUNCTION__ << std::endl;
}

int	Enemy::getFireRate() const {
	return this->_fireRate;
}

int	Enemy::getMoveRate() const {
	return this->_moveRate;
}

int Enemy::incrementMove() {
	this->_move += rand(1, 3);

	if (this->_move >= this->_moveRate) {
		this->_move = 0;
		return 1;
	}
	return 0;
}

int Enemy::incrementFire() {
	this->_fire += rand(1, 3);

	if (this->_fire >= this->_fireRate) {
		this->_fire = 0;
		return 1;
	}
	return 0;
}