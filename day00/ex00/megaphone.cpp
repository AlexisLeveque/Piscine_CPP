//
// Created by Alexis LEVEQUE on 5/28/18.
//

#include <iostream>


char    *to_upper(char *string) {
    int index = 0;

    while (string[index]) {
        if (string[index] >= 97 && string[index] <= 122)
            string[index] -= 32;
        index ++;
    }
    return string;
}


int     main(int argc, char *argv[]) {
    int index = 1;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else {
        while (index < argc) {
            std::cout << to_upper(argv[index]);
            index ++;
        }
        std::cout << std::endl;
    }

    return 0;
}