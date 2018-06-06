//
// Created by Alexis LEVEQUE on 6/6/18.
//

#ifndef EX02_ARRAY_HPP
#define EX02_ARRAY_HPP

#include <iostream>

template <typename T>
class Array {

public:
	Array(void) {
		_tab = new T[0];
		_size = 0;
	}

	Array(unsigned int n) {
		_tab = new T[n];
		_size = n;
	}

	Array(Array const &src) {
		_size = src.size();
		_tab = new T[_size];
		for (int i = 0; i < _size; ++i) {
			_tab[i] = src[i];
		}
	}

	Array &operator=(Array const &rhs) {
		_size = rhs.size();
		_tab = new T[_size];
		for (int i = 0; i < _size; ++i) {
			_tab[i] = rhs[i];
		}
		return *this;
	}

	T &operator[](size_t i) {
		if (i >= _size) {
			throw std::out_of_range("OutOfRangeException");
		}
		else {
			return _tab[i];
		}
	}

	~Array(void) {
		delete[](_tab);
	}

	size_t	size(void) const {
		return _size;
	}

private:
	T		*_tab;
	size_t	_size;

};


#endif //EX02_ARRAY_HPP
