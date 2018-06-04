//
// Created by Alexis LEVEQUE on 6/3/18.
//

#include "ft_retro.hpp"
#include "Bullet.hpp"
#include <unistd.h>


void	game_over(Screen *screen) {
	screen->setGameOver();
	box(screen->getGame()->getWindow(), 0, 0);
	Window * gameWin = screen->getGame();
	mvwprintw(gameWin->getWindow(), gameWin->getHeight()/2 - 1, (gameWin->getWidth() - 5)/2, "%s", "Game Over");
	mvwprintw(gameWin->getWindow(), gameWin->getHeight()/2 + 1, (gameWin->getWidth() - 5)/2, "Score: %u", (screen->getCharacter().getKill() * 2) - (screen->getCharacter().getShot()/20) + (screen->getCharacter().getPowerUp()*2) + screen->getTimeElapsed() / 2);
	wrefresh(screen->getGame()->getWindow());
}

void	collide(Screen *screen, Element *element1, Element *element2) {
	switch (element1->getType()) {
		case CHARACTER: {

			switch (element2->getType()) {
				case BULLET: {
					log << "Collision :Character vs bullet" <<  std::endl;

					if (((Bullet*)element2)->getDir() == DOWN) {
						screen->deleteElement(screen->getElement(element2));
						if (!(((Character*)element1)->decreaseHP())) {
							game_over(screen);
						}
						else
							screen->setDamageScreen(3);
					}
					else
						screen->deleteElement(screen->getElement(element2));
					break;
				}
				case ENEMY: {
					log << "Collision : Character vs ennemy" <<  std::endl;
					game_over(screen);
					break;
				}
				case OBSTACLE: {
					game_over(screen);
					break;
				}
				case POWERUP:{
					log << "Collision : PowerUp vs Character" <<  std::endl;
					((Character*)element1)->increaseHP();
					((Character*)element1)->increasePowerUp();
					screen->deleteElement(screen->getElement(element2));
					break;
				}
				default: {
					log << "Collision : Character vs Default" << std::endl;
					break;
				}
			}

			break;
		}
		case BULLET: {
			switch (element2->getType()) {
				case CHARACTER:{
					log << "Collision : Bullet vs Character" <<  std::endl;

					if (((Bullet*)element1)->getDir() == DOWN) {
						screen->deleteElement(screen->getElement(element1));
						if (!(((Character *)element2)->decreaseHP())) {
							game_over(screen);
						}
						else
							screen->setDamageScreen(3);
					}
					break;
				}
				case ENEMY: {
					log << "Collision : Bullet vs enemy" <<  std::endl;
					if (((Bullet*)element1)->getDir() == UP) {
						screen->getCharacter().increaseKill();
						screen->deleteElement(screen->getElement(element1));
						screen->deleteElement(screen->getElement(element2));
					}
					break;
				}
				case OBSTACLE: {
					screen->deleteElement(screen->getElement(element1));
					break;
				}
				case BULLET: {
					if (((Bullet *)element1)->getDir() != ((Bullet *)element2)->getDir())
					{
						screen->deleteElement(screen->getElement(element1));
						screen->deleteElement(screen->getElement(element2));
					}
					else
						screen->deleteElement(screen->getElement(element1));
					break;
				}
				case POWERUP: {
					screen->deleteElement(screen->getElement(element1));
					screen->deleteElement(screen->getElement(element2));
				}
				default: {
				}
			}
			break;
		}
		case ENEMY: {
			switch (element2->getType()) {
				case CHARACTER:{
					log << "Collision : Enemy vs Character" <<  std::endl;
					game_over(screen);
					break;
				}
				case BULLET: {
					log << "Collision : Enemy vs Bullet" <<  std::endl;
					if (((Bullet*)element2)->getDir() == UP) {
						screen->getCharacter().increaseKill();
						screen->deleteElement(screen->getElement(element1));
						screen->deleteElement(screen->getElement(element2));
					}
					break;
				}
				case ENEMY: {
					log << "Collision : Enemy vs Enemy" <<  std::endl;
					break;
				}
				case OBSTACLE: {
					screen->deleteElement(screen->getElement(element1));
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case OBSTACLE: {
			switch (element2->getType()) {
				case ENEMY: {
					screen->deleteElement(screen->getElement(element2));
					break;
				}
				case CHARACTER: {
					game_over(screen);
					break;
				}
				case BULLET: {
					screen->deleteElement(screen->getElement(element1));
					break;
				}
				default: {
					break;
				}
			}
			break;
		}
		case POWERUP: {
			switch (element2->getType()) {
				case CHARACTER:{
					log << "Collision : PowerUp vs Character" <<  std::endl;
					((Character*)element2)->increaseHP();
					((Character*)element2)->increasePowerUp();
					screen->deleteElement(screen->getElement(element1));
					break;
				}
				case BULLET: {
					screen->deleteElement(screen->getElement(element1));
					screen->deleteElement(screen->getElement(element2));
				}
				default: {
					break;
				}
			}
			break;
		}
	}
}


void	collision_test(Screen *screen, Element *element) {
	Element	*testElem;
	Element &character = screen->getCharacter();

	switch (element->getType()) {
		case OBSTACLE: {
			if (((Obstacle *)element)->collide(character)) {
				collide(screen, element, &character);
			}
			for (size_t i = 0; (testElem = screen->getElement(i)); ++i) {
				if (element != testElem && ((Obstacle *)element)->collide(*testElem)) {
					collide(screen, element, testElem);
					return;
				}
			}
			break;
		}
		default: {
			if (element->collide(character)) {
				collide(screen, element, &character);
			}
			for (size_t i = 0; (testElem = screen->getElement(i)); ++i) {
				if (element != testElem && element->collide(*testElem)) {
					collide(screen, element, testElem);
					return;
				}
			}
			break;
		}
	}
}