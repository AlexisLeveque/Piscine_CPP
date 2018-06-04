#include "Obstacle.hpp"
#include "Log.hpp"

int		rand(int min, int max);

Obstacle::Obstacle(void) : Element(OBSTACLE, ' ')
{
	_n_elements = 0;
	log << __PRETTY_FUNCTION__ << std::endl;
}

Obstacle::Obstacle(int pos_x, int pos_y) : Element(OBSTACLE, ' ')
{
	_n_elements = rand(MIN_ELEMENTS, MAX_ELEMENTS);
	for (size_t i = 0; i < _n_elements; i++)
	{
		_elements[i] = new Element(OBSTACLE, getCharacter());
		_elements[i]->setCoordX(rand(pos_x, pos_x + 2));
		_elements[i]->setCoordY(rand(pos_y, pos_y + 2));
		log << __PRETTY_FUNCTION__ << " x:" << _elements[i]->getCoordX() << " y:" << _elements[i]->getCoordY() << std::endl;
	}
	log << __PRETTY_FUNCTION__ << std::endl;
}

Obstacle::Obstacle(const Obstacle &b) : Element(OBSTACLE, ' ')
{
	_n_elements = b.getNElements();
	for (size_t i = 0; i < _n_elements; i++)
		_elements[i] = new Element(*b.getElement(i));
	_n_elements = 0;
	log << __PRETTY_FUNCTION__ << std::endl;
}

Obstacle::~Obstacle(void)
{
	for (size_t i = 0; i < _n_elements; i++)
		delete (_elements[i]);
	log << __PRETTY_FUNCTION__ << std::endl;
}

Obstacle	&Obstacle::operator=(const Obstacle &b)
{
	_n_elements = b.getNElements();
	for (size_t i = 0; i < _n_elements; i++)
		_elements[i] = new Element(*b.getElement(i));
	return (*this);
}

size_t		Obstacle::getNElements(void) const
{
	return (_n_elements);
}

Element		*Obstacle::getElement(size_t idx) const
{
	if (idx < _n_elements)
		return (_elements[idx]);
	return (NULL);
}

void		Obstacle::deleteElement(size_t idx)
{
	if (idx < _n_elements)
	{
		delete (_elements[idx]);
		for (size_t i = idx; i < _n_elements - 1; i++)
			_elements[i] = _elements[i + 1];
		_n_elements--;
	}
}

void Obstacle::setCoordY(int)
{
}

void Obstacle::setCoordX(int)
{
}

int Obstacle::incrementX(Window *window)
{
	bool	end = true;

	for (size_t i = 0; i < _n_elements; i++)
		if (_elements[i]->incrementX(window) != -1)
			end = false;
	if (end == true)
		return (-1);
	else
		return (0);
}

int Obstacle::incrementY(Window *window)
{
	bool	end = true;

	for (size_t i = 0; i < _n_elements; i++)
		if (_elements[i]->incrementY(window) != -1)
			end = false;
	if (end == true)
		return (-1);
	else
		return (0);
}

int Obstacle::decrementX(Window *window)
{
	bool	end = true;

	for (size_t i = 0; i < _n_elements; i++)
		if (_elements[i]->decrementX(window) != -1)
			end = false;
	if (end == true)
		return (-1);
	else
		return (0);
}

int Obstacle::decrementY(Window *window)
{
	bool	end = true;

	for (size_t i = 0; i < _n_elements; i++)
		if (_elements[i]->decrementY(window) != -1)
			end = false;
	if (end == true)
		return (-1);
	else
		return (0);
}

void Obstacle::printSelf(Window *window) const
{
	log << __PRETTY_FUNCTION__ << std::endl;
	for (size_t i = 0; i < _n_elements; i++)
		_elements[i]->printSelf(window);
}

bool Obstacle::collide(const Element &b) const
{
	for (size_t i = 0; i < _n_elements; i++)
		if (_elements[i]->collide(b))
			return (true);
	return (false);
}
