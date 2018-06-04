#include "ft_retro.hpp"

void	draw_game(Screen *screen)
{
	Element	*element;

	if (!screen->getGameOver())
	{
		screen->getGame()->clear();
		// wclear(screen->getGame()->getWindow());
		screen->getCharacter().printSelf(screen->getGame());
		for (size_t i = 0; (element = screen->getElement(i)) != NULL; i++)
		{
			log << "drawing '" << element->getCharacter() << "' at (" << element->getCoordX() << ";" << element->getCoordY() << ")" << std::endl;
			switch (element->getType())
			{
				case OBSTACLE: {
					((Obstacle *)element)->printSelf(screen->getGame());
					break;
				}
				default: {
					element->printSelf(screen->getGame());
				}
			}
		}
		box(screen->getGame()->getWindow(), 0, 0);
		wrefresh(screen->getGame()->getWindow());
	}
}

void	draw_menu(Screen *screen)
{
	size_t	t;

	t = screen->getTimeElapsed();
	// wclear(screen->getMenu()->getWindow());
	if (!screen->getGameOver())
	{
		screen->getMenu()->clear();
		mvwprintw(screen->getMenu()->getWindow(), 2, 5, "Level : %d ", screen->getLevel());
		mvwprintw(screen->getMenu()->getWindow(), 3, 5, "Score : %d ",
			  (screen->getCharacter().getKill() * 2) - (screen->getCharacter().getShot()/20) + (screen->getCharacter().getPowerUp()*2) + t / 2);
		mvwprintw(screen->getMenu()->getWindow(), 1, 5, "Lives : %d", screen->getCharacter().getHP());
		mvwprintw(screen->getMenu()->getWindow(), 4, 5, "Time : %.2u:%.2u", (t / 60) % 60, t % 60);
		mvwprintw(screen->getMenu()->getWindow(), 5, 5, "Enemies Killed : %d", screen->getCharacter().getKill());
		mvwprintw(screen->getMenu()->getWindow(), 6, 5, "Shot Fired : %d ", screen->getCharacter().getShot());
		mvwprintw(screen->getMenu()->getWindow(), 7, 5, "Life Up taken : %d ", screen->getCharacter().getPowerUp());
	}
	else
		mvwprintw(screen->getMenu()->getWindow(), 1, 5, "Lives : 0 ");

	box(screen->getMenu()->getWindow(), 0, 0);
	wrefresh(screen->getMenu()->getWindow());
}

void	draw_elements(Screen *screen)
{
	if (!screen->getGameOver())
		draw_game(screen);
	draw_menu(screen);
}

void	draw_damage_screen(Window *window)
{
	window->clear();
	wattrset(window->getWindow(), COLOR_PAIR(8) | A_DIM);
	for (int i = 0; i < window->getWidth(); i++)
		for (int j = 0; j < window->getHeight(); j++)
			mvwaddch(window->getWindow(), j, i, ' ');
	wrefresh(window->getWindow());
}
