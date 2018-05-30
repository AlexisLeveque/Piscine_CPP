//
// Created by Alexis LEVEQUE on 5/30/18.
//

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_value = 0;

}

Fixed::Fixed(int const nbr) {

    this->_value = nbr << this->_fixed;
}

Fixed::Fixed(float const nbr) {

    this->_value = (int)(nbr * (1 << 8));
}

Fixed::Fixed(Fixed const &src) {
    *this = src;

}

Fixed::~Fixed(void) {

}



Fixed &Fixed::operator=(Fixed const &rhs) {
    this->setRawBits(rhs.getRawBits());
    return *this;
}


bool Fixed::operator>(Fixed const &rhs) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {
    return this->getRawBits() != rhs.getRawBits();
}

Fixed Fixed::operator+(Fixed const &rhs) {
    Fixed res;
    res.setRawBits(this->getRawBits() + rhs.getRawBits());
    return res;
}

Fixed Fixed::operator-(Fixed const &rhs) {
    Fixed res;
    res.setRawBits(this->getRawBits() - rhs.getRawBits());
    return res;
}

Fixed Fixed::operator*(Fixed const &rhs) {
    Fixed res;
    res.setRawBits((this->getRawBits() * rhs.getRawBits()) >> this->_fixed);
    return res;
}

Fixed Fixed::operator/(Fixed const &rhs) {
    Fixed res;
    res.setRawBits((this->getRawBits() << this->_fixed) / rhs.getRawBits());
    return res;
}

Fixed Fixed::operator++() {
    this->_value++;
    return *this;
}

Fixed Fixed::operator++( int i ) {
    i = 0;
    Fixed newFixed= *this;
    this->_value++;
    return newFixed;

}


Fixed Fixed::operator--() {
    this->_value--;
    return *this;
}


Fixed Fixed::operator--( int i ) {
    i = 0;
    Fixed newFixed = *this;
    *this = this->_value--;
    return newFixed;
}

int Fixed::getRawBits() const {
    return this->_value;
}


void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}


int Fixed::toInt() const {
    return (int)roundf(this->toFloat());
}

float Fixed::toFloat() const {
    return ((float)this->_value/(1 << 8));
}

Fixed& Fixed::max(Fixed &nbr1, Fixed &nbr2) {
    return nbr1 >= nbr2 ? nbr1 : nbr2;
}

Fixed& Fixed::min(Fixed &nbr1, Fixed &nbr2) {
    return nbr1 <= nbr2 ? nbr1 : nbr2;
}

const Fixed& Fixed::max(Fixed const & nbr1, Fixed const & nbr2) {
    return nbr1 >= nbr2 ? nbr1 : nbr2;
}

const Fixed& Fixed::min(Fixed const & nbr1, Fixed const & nbr2) {
    return nbr1 <= nbr2 ? nbr1 : nbr2;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {
    o << rhs.toFloat();
    return o;
}