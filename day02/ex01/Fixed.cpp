//
// Created by Alexis LEVEQUE on 5/30/18.
//

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_value = 0;

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const nbr) {
    std::cout << "Int constructor called" << std::endl;

    this->_value = nbr << this->_fixed;
}

Fixed::Fixed(float const nbr) {
    std::cout << "Float constructor called" << std::endl;

    this->_value = (int)(nbr * (1 << 8));
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;

}

Fixed::~Fixed(void) {
    std::cout << "Destructor called" << std::endl;

}


int Fixed::toInt() const {
    return (int)roundf(this->toFloat());
}

float Fixed::toFloat() const {
    return ((float)this->_value/(1 << 8));
}


Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(rhs.getRawBits());
    return *this;
}


int Fixed::getRawBits() const {
    return this->_value;
}


void Fixed::setRawBits(int const raw) {
    this->_value = raw;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {
    o << rhs.toFloat();
    return o;
}