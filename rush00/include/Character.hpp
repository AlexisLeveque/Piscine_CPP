#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "Element.hpp"

class	Character : public Element
{
	public:
		Character(void);
		Character(const Character &b);
		~Character(void);

		Character	&operator=(const Character &b);
		int			getHP(void) const;
		int			getHPMax(void) const;
		int			decreaseHP(void);
		void		increaseKill(void);
		void		increaseShot(void);
		void		increaseHP(void);
		void		increasePowerUp(void);


		int			getKill(void);
		int			getShot(void);
		int			getPowerUp(void);


private:
		int		_hp;
		int		_hp_max;
		int		_shotFired;
		int		_kill;
		int		_powerUp;
};

#endif
