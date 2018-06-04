//
// Created by Alexis LEVEQUE on 6/2/18.
//

#include "Bullet.hpp"
#include "Log.hpp"

Bullet::Bullet(void) {}


Bullet::Bullet(int x, int y, e_dir dir) : Element(BULLET, '|'), _refreshTime(4), _refresh(0) {

	log << __PRETTY_FUNCTION__ << std::endl;

	this->setCoordX(x);
	this->setCoordY(y);
	(void)this->_refreshTime;
	(void)this->_refresh;
	this->_dir = dir;
}


Bullet::Bullet(Bullet const &src) : Element(BULLET, '|'), _refreshTime(4), _refresh(0) {
	log << __PRETTY_FUNCTION__ << std::endl;

	this->setCoordX(src.getCoordX());
	this->setCoordY(src.getCoordY());
}

Bullet &Bullet::operator=(Bullet const &rhs) {
	log << __PRETTY_FUNCTION__ << std::endl;

	this->setCoordX(rhs.getCoordX());
	this->setCoordY(rhs.getCoordY());
	return *this;
}

Bullet::~Bullet(void) {
	log << __PRETTY_FUNCTION__ << std::endl;

}

e_dir	Bullet::getDir(void) const
{
	return (_dir);
}

int Bullet::incrementRefresh() {
	this->_refresh++;
//	log << refresh  << std::endl;

	if (this->_refresh == this->_refreshTime) {
		this->_refresh = 0;
		return 1;
	}
	return 0;
}
