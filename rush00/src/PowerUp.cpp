//
// Created by Alexis LEVEQUE on 6/3/18.
//

#include "Log.hpp"
#include "PowerUp.hpp"

PowerUp::PowerUp(void) {}

PowerUp::PowerUp(int x, int y) : Element(POWERUP, '3'), _refresh(0), _refreshTime(40) {
	log << __PRETTY_FUNCTION__ << std::endl;
	this->setCoordX(x);
	this->setCoordY(y);
}

PowerUp::PowerUp(PowerUp const &src) : Element(POWERUP, '3'), _refresh(0), _refreshTime(40){
	log << __PRETTY_FUNCTION__ << std::endl;
	this->setCoordX(src.getCoordX());
	this->setCoordY(src.getCoordY());
}

PowerUp &PowerUp::operator=(PowerUp const &rhs) {
	log << __PRETTY_FUNCTION__ << std::endl;
	this->setCoordX(rhs.getCoordX());
	this->setCoordY(rhs.getCoordY());
	return *this;
}

PowerUp::~PowerUp(void) {
	log << __PRETTY_FUNCTION__ << std::endl;
}

int PowerUp::incrementRefresh() {
	this->_refresh++;

	if (this->_refresh >= this->_refreshTime) {
		this->_refresh = 0;
		return 1;
	}
	return 0;
}