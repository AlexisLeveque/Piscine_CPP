//
// Created by Alexis LEVEQUE on 5/29/18.
//

void memoryLeak()
{
    std::string* panthere = new std::string("String panthere");
    std::cout << *panthere << std::endl;
    delete panthere;
}