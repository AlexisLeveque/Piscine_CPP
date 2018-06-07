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

int return_diff(int a, int b) {
	return a-b;
}

int Span::shortestSpan() {
	if (_vector.size() > 1) {
		sort(_vector.begin(), _vector.end());
		int res = _vector[0] - _vector[1];
		if (for_each(_vector.begin(), _vector.end(), return_diff)) {
			
		}
	}
	else {
		throw NoSpanException();
	}
}
