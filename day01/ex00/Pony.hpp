//
// Created by Alexis LEVEQUE on 5/29/18.
//

#ifndef PISCINE_PONY_HPP
#define PISCINE_PONY_HPP


class Pony {

public:
    Pony( int height );
    ~Pony( void );
    void run( void ) const ;
    void setHeight( int height );
    int getHeight();

private:
    int _height;

};


#endif //PISCINE_PONY_HPP
