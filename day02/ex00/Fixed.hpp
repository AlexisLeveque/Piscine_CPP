//
// Created by Alexis LEVEQUE on 5/30/18.
//

#ifndef EX00_FIXED_HPP
#define EX00_FIXED_HPP


class Fixed {


public:
    Fixed(void);

    Fixed(Fixed const &src);

    ~Fixed(void);

    Fixed &operator=(Fixed const &rhs);

    int getRawBits( void ) const;

    void setRawBits( int const raw );


private:
    int _fpv;
    static const int _fixed = 8;

};


#endif //EX00_FIXED_HPP
