#ifndef SCREEN_HPP
# define SCREEN_HPP

# include <ncurses.h>
# include "Window.hpp"
# include "Element.hpp"
# include "Character.hpp"
# include "Obstacle.hpp"
# include <sys/time.h>

# define COLOR_ORANGE	8

# define KEY_ESCAPE		27
# define ELEMENTS_MAX	1024

class	Screen
{
	public:
		Screen(void);
		Screen(const Screen &b);
		~Screen(void);

		Screen	&operator=(const Screen &b);

		Window		*getMenu(void) const;
		Window		*getGame(void) const;
		Character	&getCharacter(void);
		size_t		getNElements(void) const;
		Element		*getElement(size_t idx);
		int			getElement(Element *elem);
		bool		addElement(Element *element);
		void		deleteElement(size_t idx);
		bool		getGameOver();
		void		setGameOver();
		void		incrementLevel();
		int			getLevel();
		size_t		getTimeElapsed(void) const;
		void		setDamageScreen(int);
		int			getDamageScreen(void);
	private:
		Window			*_menu;
		Window			*_game;
		Element			*_elements[ELEMENTS_MAX];
		size_t			_n_elements;
		Character		_character;
		bool			_gameOver;
		int				_level;
		struct timeval	_start_time;
		int 			_damage_screen;
};

#endif
