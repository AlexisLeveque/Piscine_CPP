#include <iostream>

void displayRes(std::string first, std::string second, std::string third, std::string fourth) {
    std::cout << "char: " << first << std::endl;
    std::cout << "int: " << second << std::endl;
    std::cout << "float: " << third << std::endl;
    std::cout << "double: " << fourth << std::endl;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        std::cout << "I need one argument" << std::endl;
        return 0;
    }
    const std::string nbr = argv[1];
    if (nbr == "nan" || nbr == "-inf" || nbr == "+inf") {
        displayRes("impossible", "impossible", nbr + "f", nbr);
    }
    if (nbr == "nanf" || nbr == "-inff" || nbr == "+inff") {
        displayRes("impossible", "impossible", nbr, nbr.substr(0, nbr.size()-1));
    }
    if (nbr[0].isChar)
    return 0;
}