#ifndef OBSTACLE_HPP
# define OBSTACLE_HPP

# include "Element.hpp"

# define MIN_ELEMENTS	4
# define MAX_ELEMENTS	9

class	Obstacle : public Element
{
	public:
		Obstacle(void);
		Obstacle(int pos_x, int pos_y);
		Obstacle(const Obstacle &b);
		~Obstacle(void);

		Obstacle	&operator=(const Obstacle &b);

		size_t		getNElements(void) const;
		Element		*getElement(size_t idx) const;
		void		deleteElement(size_t idx);

		void setCoordY(int);
		void setCoordX(int);
		int incrementX(Window *window);
		int incrementY(Window *window);
		int decrementX(Window *window);
		int decrementY(Window *window);

		void printSelf(Window *window) const;

		bool collide(const Element &b) const;
	private:
		Element		*_elements[MAX_ELEMENTS];
		size_t		_n_elements;
};

#endif
