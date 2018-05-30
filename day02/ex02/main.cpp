#include <iostream>
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    Fixed c(10.5f);
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;
    std::cout << Fixed::max( b, a ) << std::endl;
    std::cout << Fixed::min( a, b ) << std::endl;
    std::cout << Fixed::min( b, a ) << std::endl;

    a = Fixed(5);
    std::cout << a + b << std::endl;
    std::cout << a - c << std::endl;
    std::cout << a * b << std::endl;
    std::cout << c / a << std::endl;
    
    return 0;
}