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

public:
    Fixed &operator=(Fixed const &rhs);
    bool operator>(Fixed const &rhs) const ;
    bool operator<(Fixed const &rhs) const ;
    bool operator>=(Fixed const &rhs) const ;
    bool operator<=(Fixed const &rhs) const ;
    bool operator==(Fixed const &rhs) const ;
    bool operator!=(Fixed const &rhs) const ;
    Fixed operator+(Fixed const &rhs);
    Fixed operator-(Fixed const &rhs);
    Fixed operator*(Fixed const &rhs);
    Fixed operator/(Fixed const &rhs);
    Fixed operator++();
    Fixed operator++( int i );
    Fixed operator--();
    Fixed operator--( int i );




public:
    int getRawBits( void ) const;
    void setRawBits( int const raw );

    float toFloat ( void ) const;
    int toInt( void ) const;

public:
    static Fixed &max(Fixed & nbr1, Fixed & nbr2);
    static const Fixed &max(Fixed const & nbr1, Fixed const & nbr2);

    static Fixed &min(Fixed & nbr1, Fixed & nbr2);
    static const Fixed &min(Fixed const & nbr1, Fixed const & nbr2);

private:
    int _value;
    static const int _fixed = 8;

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs );

#endif //EX00_FIXED_HPP
