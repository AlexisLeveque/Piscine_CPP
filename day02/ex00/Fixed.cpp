//
// Created by Alexis LEVEQUE on 5/30/18.
//

#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_fpv = 0;

    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    this->_fpv = src.getRawBits();

}

Fixed::~Fixed(void) {}

Fixed &Fixed::operator=(Fixed const &rhs) {
    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(rhs.getRawBits());
    return *this;
}


int Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fpv;
}


void Fixed::setRawBits(int const raw) {
    this->_fpv = raw;
}