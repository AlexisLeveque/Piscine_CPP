#ifndef WINDOW_HPP
# define WINDOW_HPP

# include <ncurses.h>

class	Window
{
	public:
		Window(void);
		Window(int x, int y, int width, int height);
		Window(const Window &b);
		~Window(void);

		Window	&operator=(const Window &b);

		int		getX(void) const;
		int		getY(void) const;
		int		getWidth(void) const;
		int		getHeight(void) const;
		WINDOW	*getWindow(void) const;

		void	clear(void);
	private:
		int		_x, _y, _width, _height;
		WINDOW	*_window;
};

#endif
