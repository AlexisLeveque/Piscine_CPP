//
// Created by Alexis LEVEQUE on 6/2/18.
//

#ifndef FT_RETRO_ELEMENT_HPP
#define FT_RETRO_ELEMENT_HPP

#include "Window.hpp"

enum	e_type
{
	CHARACTER,
	ENEMY,
	BULLET,
	OBSTACLE,
	POWERUP
};

class Element {

public:
	Element(e_type type, char character);

	Element(Element const &src);

	Element &operator=(Element const &rhs);

	~Element(void);

	char getCharacter() const ;
	int getCoordX() const ;
	int getCoordY() const ;
	e_type	getType(void) const;
	void setCharacter(char);
	void setCoordY(int);
	void setCoordX(int);
	int incrementX(Window *window);
	int incrementY(Window *window);
	int decrementX(Window *window);
	int decrementY(Window *window);

	void printSelf(Window *window);

	bool collide(const Element &b);

protected:
	Element(void);

private:
	e_type _type;
	char _character;
	int _coordX;
	int _coordY;

};


#endif //FT_RETRO_ELEMENT_HPP
