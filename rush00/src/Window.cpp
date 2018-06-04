#include "Window.hpp"
#include "Log.hpp"

Window::Window(void)
{
	log << __PRETTY_FUNCTION__ << std::endl;
	_x = 0;
	_y = 0;
	_width = 0;
	_height = 0;
	if (!(_window = newwin(_height, _width, _y, _x)))
	{
		log << "cannot create window" << std::endl;
		exit(1);
	}
}

Window::Window(int x, int y, int width, int height)
{
	log << __PRETTY_FUNCTION__ << std::endl;
	log << "x:" << x << " y:" << y << " width:" << width << " height" << height << std::endl;
	_x = x;
	_y = y;
	_width = width;
	_height = height;
	if (!(_window = newwin(_height, _width, _y, _x)))
	{
		log << "cannot create window" << std::endl;
		exit(1);
	}
	log << "_x:" << _x << " _y:" << _y << " _width:" << _width << " _height" << _height << std::endl;
	wrefresh(_window);
}

Window::Window(const Window &b)
{
	log << __PRETTY_FUNCTION__ << std::endl;
	_x = b.getX();
	_y = b.getY();
	_width = b.getWidth();
	_height = b.getHeight();
	if (!(_window = newwin(_height, _width, _y, _x)))
	{
		log << "cannot create window" << std::endl;
		exit(1);
	}
}

Window::~Window(void)
{
	log << __PRETTY_FUNCTION__ << std::endl;
	delwin(_window);
}

Window	&Window::operator=(const Window &b)
{
	_x = b.getX();
	_y = b.getY();
	_width = b.getWidth();
	_height = b.getHeight();
	return (*this);
}

int		Window::getX(void) const
{
	return (_x);
}

int		Window::getY(void) const
{
	return (_y);
}

int		Window::getWidth(void) const
{
	return (_width);
}

int		Window::getHeight(void) const
{
	return (_height);
}

WINDOW	*Window::getWindow(void) const
{
	return (_window);
}

void	Window::clear(void)
{
	std::string	str;

	str.resize(_width + 1);
	for (size_t i = 0; i < str.length(); i++)
		str[i] = ' ';
	for (int h = 0; h < _height; h++)
		mvwaddstr(_window, h, 0, str.c_str());
}
