#include "ft_retro.hpp"
#include "Bullet.hpp"
#include "PowerUp.hpp"
#include "Enemy.hpp"
#include "Log.hpp"


int		rand(int min, int max)
{
	if (!(max - min + 1))
		return (min);
	return ((std::rand() % (max - min + 1)) + min);
}

void	manage_inputs(Screen *screen)
{
	int		c;

	(void)screen;
	if ((c = getch()) != ERR)
	{
		//	got input;
		switch (c)
		{
			case 27:
				exit(1);
				break ;
			case KEY_LEFT:
				if (!screen->getGameOver()) {
					screen->getCharacter().decrementX(screen->getGame());
					collision_test(screen, &screen->getCharacter());
				}
				break;
			case KEY_RIGHT:
				if (!screen->getGameOver()) {
					screen->getCharacter().incrementX(screen->getGame());
					collision_test(screen, &screen->getCharacter());
				}
				break;
			case KEY_DOWN:
				if (!screen->getGameOver()) {
					screen->getCharacter().incrementY(screen->getGame());
					collision_test(screen, &screen->getCharacter());
				}
				break;
			case KEY_UP:
				if (!screen->getGameOver()) {
					screen->getCharacter().decrementY(screen->getGame());
					collision_test(screen, &screen->getCharacter());
				}
				break;
			case ' ':
				if (!screen->getGameOver()) {
					screen->addElement(
							new Bullet(screen->getCharacter().getCoordX(), screen->getCharacter().getCoordY() - 1, UP));
					collision_test(screen, screen->getElement(screen->getNElements() - 1));
					screen->getCharacter().increaseShot();
					log << "launching bullet ! " << screen->getNElements() << std::endl;
				}
				break;
			default:
				log << "key '" << c << "' not handled" << std::endl;
				break;
		}
	}
}

void	manage_enemy(Screen *screen, Enemy *enemy, size_t idx) {
	if (enemy->incrementFire() == 1) {
		Element *element = screen->getElement(idx);
		screen->addElement(new Bullet(element->getCoordX(), element->getCoordY() + 1, DOWN));
	}
	if (enemy->incrementMove() == 1) {
		if (rand(1, 20) == 1) {
			if (rand(1, 2) == 1) {
				enemy->incrementX(screen->getGame());
			}
			else {
				enemy->decrementX(screen->getGame());
			}
		}
		if (enemy->incrementY(screen->getGame()) == -1) {
			screen->deleteElement(idx);
			log << "Enemy deleted ! " << screen->getNElements() << std::endl;
		}
		else {
			log << "Enemy Collision test ! " << screen->getNElements() << std::endl;
			collision_test(screen, screen->getElement(idx));
		}
	}

}

Enemy *rand_enemy(int width) {
	int x = rand(1, width - 2);
	int y = rand(1, 4);

	switch (rand(1, 3)) {
		case 1:
			return new Enemy('U', 400, 040, x, y);
		case 2:
			return new Enemy('W', 300, 070, x, y);
		case 3:
			return new Enemy('O', 200, 100, x, y);
	}
	return nullptr;
}


void	manage_bullet(Screen *screen, Bullet *bullet, size_t idx)
{
	if (bullet->incrementRefresh() == 1) {
		switch (bullet->getDir()) {
			case UP:
				if (bullet->decrementY(screen->getGame()) == -1) {
					screen->deleteElement(idx);
					log << "bullet deleted ! " << screen->getNElements() << std::endl;
				}
				else
					collision_test(screen, screen->getElement(idx));
				break;
			case DOWN:
				if (bullet->incrementY(screen->getGame()) == -1) {
					screen->deleteElement(idx);
					log << "bullet deleted ! " << screen->getNElements() << std::endl;
				} else
					collision_test(screen, screen->getElement(idx));
				break;
			default:
				log << "invalid bullet direction, wtf ?!?" << std::endl;
				break;
		}
	}
}

void	manage_elements(Screen *screen)
{
	static int	cycle = 0;
	Element	*element;

	cycle++;
	if (cycle % 1500 == 0)
		screen->incrementLevel();
	for (size_t i = 0; (element = screen->getElement(i)); i++)
	{
		switch (element->getType())
		{
			case BULLET:
				manage_bullet(screen, (Bullet *)element, i);
				break;
			case ENEMY:
				manage_enemy(screen, (Enemy *)element, i);
				break;
			case OBSTACLE:
				if (!(cycle % 200))
					if (((Obstacle *)element)->incrementY(screen->getGame()) == -1)
						screen->deleteElement(i);
				break;
			case POWERUP:
				if (!(cycle % 200)) {
					if (((PowerUp *) element)->incrementY(screen->getGame()) == -1)
						screen->deleteElement(i);
					else
						collision_test(screen, element);
				}
				break;
			default:
				log << "element type " << element->getType() << " not handled" << std::endl;
				break;
		}
	}
	if (rand(0, 400) == 1)
		screen->addElement(new Obstacle(rand(0, screen->getGame()->getWidth() - 4), -4));
	if (rand(0, ( 150 - 10 * screen->getLevel()) > 9 ? 150 - 10 * screen->getLevel() : 10 )== 1) {
		screen->addElement(rand_enemy(screen->getGame()->getWidth()));
	}
	if (rand(0, 800) == 1) {
		screen->addElement(new PowerUp(rand(1, screen->getGame()->getWidth()-2), 1));
	}
}
