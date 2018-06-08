//
// Created by Alexis LEVEQUE on 6/7/18.
//

#include "Span.hpp"
#include <algorithm>
#include <utility>

Span::Span(void) {}

Span::Span(unsigned int nbr) {
	_size_max = nbr;
}

Span::Span(Span const &src) {}

Span &Span::operator=(Span const &rhs) {}

Span::~Span(void) {}

void Span::addNumber(int nbr) {
	if (_vector.size() < _size_max) {
		_vector.push_back(nbr);
	}
	else {
		throw TooManyNumberException();
	}
}

int Span::longestSpan() {
	if (_vector.size() > 1) {
		std::pair res = minmax_element(_vector.begin(), _vector.end());
		return *res.second - *res.first;
	}
	else {
		throw NoSpanException();
	}
}

int Span::shortestSpan() {
	if (_vector.size() > 1) {
		sort(_vector.begin(), _vector.end());
		std::vector<int>::iterator i =_vector.begin();
		int res = _vector[0] - _vector[1];
		while (i+1 != _vector.end()) {
			if (*i - *(i+1) < res) {
				res = *i - *(i+1);
			}
			i++;
		}
		return res;
	}
	else {
		throw NoSpanException();
	}
}

template<typename T>
void	addNumber(T range) {
	for (T::iterator i = range.begin(); i < range.end(); ++i) {
		addNumber(i);
	}
}
