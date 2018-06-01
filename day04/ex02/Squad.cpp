//
// Created by Alexis LEVEQUE on 6/1/18.
//

#include "Squad.hpp"
#include <iostream>

Squad::Squad(void) : _count(0) {}

Squad::Squad(Squad const &src) {
    for (int i = 0; i < src.getCount(); ++i) {
        this->_squad[i] = src.getUnit(i)->clone();
    }
    this->_count = src.getCount();
}

Squad &Squad::operator=(Squad const &rhs) {
    for (int i = 0; i < rhs.getCount(); ++i) {
        this->_squad[i] = rhs.getUnit(i)->clone();
    }
    this->_count = rhs.getCount();
    return *this;
}

Squad::~Squad(void) {
    for (int i = 0; i < this->getCount(); ++i) {
        delete this->_squad[i];
    }
}

int Squad::push(ISpaceMarine *marine) {
    if (!marine)
        return this->getCount();
    else {
        for (int i = 0; i < this->getCount(); ++i) {
            if (marine == _squad[i])
                return this->getCount();
        }
        if (this->getCount() < 50) {
            this->_squad[this->getCount()] = marine;
            this->_count++;
        }
        return this->getCount();

    }
}

ISpaceMarine* Squad::getUnit(int nbr) const {
    if (nbr < 0 || nbr >= this->getCount())
        return nullptr;
    else
        return this->_squad[nbr];
}

int Squad::getCount() const {
    return this->_count;
}