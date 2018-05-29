#include <iostream>

int main() {
    std::string brain = std::string("HI THIS IS BRAIN");

    std::string *str_ptr = &brain;
    std::string& str_ref = brain;

    std::cout << "With the pointer : " << *str_ptr << std::endl;
    std::cout << "With the reference : " << str_ref << std::endl;

    return 0;
}