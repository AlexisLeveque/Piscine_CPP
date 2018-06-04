#include "Character.hpp"

Character::Character(void) : Element(CHARACTER, '^'), _hp(3), _hp_max(6),
							 _shotFired(0), _kill(0)
{
}

Character::Character(const Character &b) : Element(CHARACTER, '^'), _hp(3), _hp_max(6),
										   _shotFired(0), _kill(0)
{
	_hp = b.getHP();
	_hp_max = b.getHPMax();
}

Character::~Character(void)
{
}

Character	&Character::operator=(const Character &b)
{
	_hp = b.getHP();
	_hp_max = b.getHPMax();
	return (*this);
}

int		Character::getHP(void) const
{
	return (_hp);
}

int		Character::getHPMax(void) const
{
	return (_hp_max);
}

int		Character::decreaseHP() {
	_hp--;
	return _hp > 0 ? 1: 0;
}

void	Character::increaseKill() {
	_kill++;
}

void	Character::increaseShot() {
	_shotFired++;
}

void	Character::increaseHP() {
	if (_hp < _hp_max)
		_hp++;
}

void	Character::increasePowerUp() {
		_powerUp++;
}

int		Character::getKill() {
	return _kill;
}

int		Character::getShot() {
	return _shotFired;
}

int		Character::getPowerUp() {
	return _powerUp;
}