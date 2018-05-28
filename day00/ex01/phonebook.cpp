//
// Created by Alexis LEVEQUE on 5/28/18.
//

#include <iostream>
#include <iomanip>
#include "Contact_class.hpp"

void            print_all(Contact contact){
    std::cout << contact.getFirst_name() << std::endl;
    std::cout << contact.getLast_name() << std::endl;
    std::cout << contact.getNickname() << std::endl;
    std::cout << contact.getLogin() << std::endl;
    std::cout << contact.getAddress() << std::endl;
    std::cout << contact.getEmail() << std::endl;
    std::cout << contact.getPhone() << std::endl;
    std::cout << contact.getBirthday() << std::endl;
    std::cout << contact.getMeal() << std::endl;
    std::cout << contact.getUnderwear() << std::endl;
    std::cout << contact.getSecret() << std::endl;
}


std::string     truncate(std::string input){
    if (input.size() > 10){
        while (input.size() >= 10){
            input.pop_back();
        }
        input.append(".");
    }
    return input;
}


Contact user_add(){
    Contact contact;
    std::string buffer;


    std::cout << "Input the first name : ";
    std::cin >> buffer;
    contact.setFirst_name(buffer);
    std::cout << "Input the last name : ";
    std::cin >> buffer;
    contact.setLast_name(buffer);
    std::cout << "Input the nikname : ";
    std::cin >> buffer;
    contact.setNickname(buffer);
    std::cout << "Input the login : ";
    std::cin >> buffer;
    contact.setLogin(buffer);
    std::cout << "Input the postal address : ";
    std::cin >> buffer;
    contact.setAddress(buffer);
    std::cout << "Input the email address : ";
    std::cin >> buffer;
    contact.setEmail(buffer);
    std::cout << "Input the phone number : ";
    std::cin >> buffer;
    contact.setPhone(buffer);
    std::cout << "Input the birthday date : ";
    std::cin >> buffer;
    contact.setBirthday(buffer);
    std::cout << "Input the favorite meal : ";
    std::cin >> buffer;
    contact.setMeal(buffer);
    std::cout << "Input the underwear color : ";
    std::cin >> buffer;
    contact.setUnderwear(buffer);
    std::cout << "Input the darkest secret : ";
    std::cin >> buffer;
    contact.setSecret(buffer);

    return contact;


}


int     main(){
    Contact contact[8];
    int     index = 0;
    while(1){
        char    buff[512];
        std::string exit = "EXIT";
        std::string add = "ADD";
        std::string search = "SEARCH";

        std::cout << "Type ADD to add a contact, type SEARCH to search a contact or type EXIT to quit all your contacts will be lost." << std::endl;
        std::cin >> buff;
        if (buff == exit){
            break;
        }
        else if (buff == add){
            if (index < 8) {
                Contact new_contact;
                new_contact = user_add();
                contact[index] = new_contact;
                index ++;
                std::cout << "Contact added successfully" << std::endl;

            }
            else {
                std::cout << "Already 8 contacts , I can't store more" << std::endl;
            }
        }
        else if (buff == search){

            if (index != 0) {
                std::cout << std::setfill (' ') << std::setw (10); std::cout << std::right << "Index";
                std::cout << "|";
                std::cout.width(10); std::cout << std::right << "First name";
                std::cout << "|";
                std::cout.width(10); std::cout << std::right << "Last name";
                std::cout << "|";
                std::cout.width(10); std::cout << std::right << "Nickname" << std::endl;
                int i = 0;

                while (i < 8 && i < index) {
                    std::cout << std::setfill(' ') << std::setw(10);
                    std::cout << std::right << i + 1;
                    std::cout << "|";
                    std::cout << std::setfill(' ') << std::setw(10);
                    std::cout << truncate(contact[i].getFirst_name());
                    std::cout << "|";
                    std::cout << std::setfill(' ') << std::setw(10);
                    std::cout << truncate(contact[i].getLast_name());
                    std::cout << "|";
                    std::cout << std::setfill(' ') << std::setw(10);
                    std::cout << truncate(contact[i].getNickname()) << std::endl;
                    i++;
                }
                std::string input;
                std::cout << "Enter the index of the contact you want to see." << std::endl;
                std::cin >> input;
                if (isdigit(input[0])) {
                    int x;
                    x = std::stoi(input);
                    if (x-1  < index and x-1 >= 0)
                        print_all(contact[x-1]);
                    else
                        std::cout << "Wrong index" << std::endl;
                }
                else
                    std::cout << "Wrong index" << std::endl;
            }
            else
                std::cout << "There is no Contact" << std::endl;
        }
        else
            std::cout << "Bad input, Try again" << std::endl;
    }
}