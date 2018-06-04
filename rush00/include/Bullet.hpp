//
// Created by Alexis LEVEQUE on 6/2/18.
//

#ifndef FT_RETRO_BULLET_HPP
#define FT_RETRO_BULLET_HPP

#include "Element.hpp"

enum	e_dir
{
	UP,
	DOWN
};

class Bullet : public Element {

public:
	Bullet(int x, int y, e_dir dir);

	Bullet(Bullet const &src);

	Bullet &operator=(Bullet const &rhs);

	~Bullet(void);

	e_dir	getDir(void) const;

	int incrementRefresh();

private:
	Bullet(void);
	int _refreshTime;
	int _refresh;
	e_dir _dir;
};


#endif //FT_RETRO_BULLET_HPP
