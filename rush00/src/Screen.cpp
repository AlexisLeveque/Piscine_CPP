#include "Screen.hpp"
#include "Log.hpp"
#include <iostream>

int		rand(int min, int max);

Screen::Screen(void)
{
	int		width, height;

	log << __PRETTY_FUNCTION__ << std::endl;
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	curs_set(FALSE);
	getmaxyx(stdscr, height, width);
	start_color();
	init_color(COLOR_ORANGE, 898, 449, 0);
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
	init_pair(6, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(7, COLOR_BLACK, COLOR_ORANGE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	srand(time(NULL));
	refresh();
	_n_elements = 0;
	_gameOver = 0;
	_level = 1;
	_damage_screen = 0;
	log << "width:" << width << " height:" << height << std::endl;
	if (width / 2 > height)
	{
		_game = new Window(width - height * 2 + 1, 1, height * 2 - 2, height - 2);
		if ((width - _game->getWidth() - 2) / 2 <= height - 2)
			_menu = new Window(1, 1, width - _game->getWidth() - 3, (width - _game->getWidth() - 2) / 2);
		else
			_menu = new Window(width - _game->getWidth() - _game->getHeight() * 2 - 1, 1, _game->getHeight() * 2, _game->getHeight());
	}
	else
	{
		_game = new Window(1, height - width / 2 + 1, width - 2, width / 2 - 2);
		if ((height - width / 2 - 1) * 2 <= width - 2)
			_menu = new Window((width - (height - width / 2 - 1) * 2) / 2, 1, (height - width / 2 - 1) * 2, height - width / 2 - 1);
		else
			_menu = new Window(1, height - _game->getHeight() - _game->getWidth() / 2 - 1, _game->getWidth(), _game->getHeight());
	}
	_character.setCoordY(_game->getHeight() - 2);
	_character.setCoordX(_game->getWidth() / 2);
	gettimeofday(&_start_time, NULL);
	int	n_obstacles = rand(4, 9);

	for (int i = 0; i < n_obstacles; i++)
		addElement(new Obstacle(rand(0, _game->getWidth() - 4), rand(0, _game->getHeight() - 12)));
}

Screen::Screen(const Screen &b)
{
	log << __PRETTY_FUNCTION__ << std::endl;
	_n_elements = 0;
	_gameOver = 0;
	_level = 1;
	_damage_screen = 0;
	_game = new Window(*b.getGame());
	gettimeofday(&_start_time, NULL);
}

Screen::~Screen(void)
{
	for (size_t i = 0; i < _n_elements; i++)
		delete (_elements[i]);
	delete (_game);
	endwin();
	log << __PRETTY_FUNCTION__ << std::endl << std::endl;
}

Screen	&Screen::operator=(const Screen &b)
{
	_game = new Window(*b.getGame());
	return (*this);
}

Window	*Screen::getGame(void) const
{
	return (_game);
}

Window	*Screen::getMenu(void) const
{
	return (_menu);
}

Character	&Screen::getCharacter(void)
{
	return (_character);
}

size_t	Screen::getNElements(void) const
{
	return (_n_elements);
}

Element	*Screen::getElement(size_t idx)
{
	if (idx < _n_elements)
		return (_elements[idx]);
	return (NULL);
}

int	Screen::getElement(Element *elem)
{
	Element *element;
	for (int i = 0; (element = this->getElement(i)); ++i) {
		if (elem == element)
			return (i);
	}
	return (-1);

}

bool	Screen::addElement(Element *element)
{
	if (_n_elements < ELEMENTS_MAX - 1)
	{
		_elements[_n_elements++] = element;
		return (true);
	}
	return (false);
}

void	Screen::deleteElement(size_t idx)
{
	log << __PRETTY_FUNCTION__ << std::endl;
	if (idx < _n_elements)
	{
		switch (_elements[idx]->getType())
		{
			case OBSTACLE: {
				delete ((Obstacle *)_elements[idx]);
				break;
			}
			default: {
				delete (_elements[idx]);
				break;
			}
		}
		for (size_t i = idx; i < _n_elements - 1; i++)
			_elements[i] = _elements[i + 1];
		_n_elements--;
	}
}

bool	Screen::getGameOver() {
	return _gameOver;
}

int		Screen::getLevel() {
	return _level;
}

void	Screen::setGameOver() {
	_gameOver = 1;
}

void	Screen::incrementLevel() {
	_level++;
}

size_t		Screen::getTimeElapsed(void) const
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (((now.tv_sec - _start_time.tv_sec) * 1000000 +
		(now.tv_usec - _start_time.tv_usec)) / 1000000);
}

void		Screen::setDamageScreen(int value)
{
	_damage_screen = value;
}

int			Screen::getDamageScreen(void)
{
	return (_damage_screen);
}
