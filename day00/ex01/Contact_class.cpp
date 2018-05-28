//
// Created by Alexis LEVEQUE on 5/28/18.
//

#include "Contact_class.hpp"

Contact::Contact() {
    return;
}

Contact::~Contact() {
    return;
}

std::string Contact::getFirst_name() const {

    return this->_first_name;
}

std::string Contact::getLast_name() const {
    return this->_last_name;
}

std::string Contact::getNickname() const {
    return this->_nickname;
}

std::string Contact::getLogin() const {
    return this->_login;
}

std::string Contact::getAddress() const {
    return this->_address;
}

std::string Contact::getEmail() const {
    return this->_email;
}

std::string Contact::getPhone() const {
    return this->_phone;
}

std::string Contact::getBirthday() const {
    return this->_birthday;
}

std::string Contact::getMeal() const {
    return this->_meal;
}

std::string Contact::getUnderwear() const {
    return this->_underwear;
}

std::string Contact::getSecret() const {
    return this->_secret;
}

void        Contact::setFirst_name(std::string str)
{
    this->_first_name = str;
    return ;
}

void        Contact::setLast_name(std::string str)
{
    this->_last_name = str;
    return ;
}

void        Contact::setNickname(std::string str)
{
    this->_nickname = str;
    return ;
}

void        Contact::setLogin(std::string str)
{
    this->_login = str;
    return ;
}

void        Contact::setAddress(std::string str)
{
    this->_address = str;
    return ;
}

void        Contact::setEmail(std::string str)
{
    this->_email = str;
    return ;
}

void        Contact::setPhone(std::string str)
{
    this->_phone = str;
    return ;
}

void        Contact::setBirthday(std::string str)
{
    this->_birthday = str;
    return ;
}

void        Contact::setMeal(std::string str)
{
    this->_meal = str;
    return ;
}

void        Contact::setUnderwear(std::string str)
{
    this->_underwear = str;
    return ;
}

void        Contact::setSecret(std::string str)
{
    this->_secret = str;
    return ;
}