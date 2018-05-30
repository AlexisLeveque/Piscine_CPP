//
// Created by Alexis LEVEQUE on 5/30/18.
//

#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP


class Fixed {


public:
    Fixed(void);

    Fixed(int const nbr);

    Fixed(float const nbr);

    Fixed(Fixed const &src);

    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    int getRawBits( void ) const;

    void setRawBits( int const raw );

    float toFloat ( void ) const;

    int toInt( void ) const;


private:
    int _value;
    static const int _fixed = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif //EX00_FIXED_HPP
