//
// Created by Alexis LEVEQUE on 6/2/18.
//

#include "Element.hpp"
#include "Log.hpp"
#include "Bullet.hpp"
#include "Obstacle.hpp"

Element::Element(void) {}


Element::Element(e_type type, char character) : _type(type), _character(character), _coordX(0), _coordY(0) {
	log << __PRETTY_FUNCTION__ << std::endl;
}


Element::Element(Element const &src) : _character(src.getCharacter()), _coordX(src.getCoordX()), _coordY(src.getCoordY()) {
	log << __PRETTY_FUNCTION__ << std::endl;
}

Element &Element::operator=(Element const &rhs) {
	log << __PRETTY_FUNCTION__ << std::endl;

	this->setCoordX(rhs.getCoordX());
	this->setCoordY(rhs.getCoordY());
	this->setCharacter(rhs.getCharacter());
	return *this;
}

Element::~Element(void) {
	log << __PRETTY_FUNCTION__ << std::endl;

}

char Element::getCharacter() const {
	return this->_character;
}

int Element::getCoordX() const {
	return this->_coordX;
}

int Element::getCoordY() const {
	return this->_coordY;
}

e_type	Element::getType(void) const
{
	return _type;
}

void Element::setCharacter(char character) {
	this->_character = character;
}

void Element::setCoordX(int x) {
	this->_coordX = x;
}

void Element::setCoordY(int y) {
	this->_coordY = y;
}

int Element::incrementX(Window *win) {
	if (this->getCoordX() < win->getWidth() - 2) {
		++this->_coordX;
		return this->getCoordX();
	}
	else
		return -1;
}

int Element::incrementY(Window *win) {
	if (this->getCoordY() < win->getHeight() - 2) {
		++this->_coordY;
		return this->getCoordY();
	}
	else
		return -1;
}

int Element::decrementX(Window *win) {
	(void)win;
	if (this->getCoordX() > 1) {
		--this->_coordX;
		return this->getCoordX();
	}
	else
		return -1;
}

int Element::decrementY(Window *win) {
	(void)win;
	if (this->getCoordY() > 1) {
		--this->_coordY;
		return this->getCoordY();
	}
	else
		return -1;
}

void Element::printSelf(Window *win) {
	switch (_type)
	{
		case CHARACTER:
			wattrset(win->getWindow(), COLOR_PAIR(4));
			break;
		case ENEMY:
			wattrset(win->getWindow(), COLOR_PAIR(2));
			break;
		case BULLET:
			if (((Bullet *)this)->getDir() == UP)
				wattrset(win->getWindow(), COLOR_PAIR(3));
			else
				wattrset(win->getWindow(), COLOR_PAIR(5));
			break;
		case OBSTACLE:
			wattrset(win->getWindow(), COLOR_PAIR(7));
			break;
		case POWERUP:
			wattron(win->getWindow(), COLOR_PAIR(6));
			break;
		default:
			wattrset(win->getWindow(), COLOR_PAIR(1));
			break;
	}
	mvwaddch(win->getWindow(), this->getCoordY(), this->getCoordX(), this->getCharacter());
	wattrset(win->getWindow(), COLOR_PAIR(1) | A_NORMAL);
}

bool Element::collide(const Element &b)
{
	switch (b.getType())
	{
		case OBSTACLE: {
			return (((Obstacle&)b).collide(*this));
		}
		default: {
			if (_coordX == b.getCoordX() && _coordY == b.getCoordY())
				return (true);
			return (false);
		}
	}
}
