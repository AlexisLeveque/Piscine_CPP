//
// Created by Alexis LEVEQUE on 5/29/18.
//

#include "Pony.hpp"
#include <iostream>

Pony ponyOnTheStack() {
    return Pony(42);

}


Pony *ponyOnTheHeap() {
    return new Pony(30);
}


int     main() {
    Pony pony1 = ponyOnTheStack();;
    Pony *pony2  = ponyOnTheHeap();

    pony1.run();
    pony2->run();
    pony1.setHeight(18);
    pony2->setHeight(80);
    std::cout << "Pony 1 new height is " << pony1.getHeight() << std::endl;
    std::cout << "Pony 2 new height is " << pony2->getHeight() << std::endl;

    delete pony2;
    return 0;
}