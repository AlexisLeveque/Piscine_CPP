//
// Created by Alexis LEVEQUE on 6/3/18.
//

#ifndef FT_RETRO_POWERUP_HPP
#define FT_RETRO_POWERUP_HPP

#include "Element.hpp"

class PowerUp : public Element {

public:
	PowerUp(int x, int y);

	PowerUp(PowerUp const &src);

	PowerUp &operator=(PowerUp const &rhs);

	~PowerUp(void);

	int incrementRefresh();

private:
	PowerUp(void);
	int _refresh;
	int _refreshTime;

};


#endif //FT_RETRO_POWERUP_HPP
