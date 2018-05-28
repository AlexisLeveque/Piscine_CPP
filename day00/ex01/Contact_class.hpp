//
// Created by Alexis LEVEQUE on 5/28/18.
//

#ifndef PISCINE_CONTACT_CLASS_HPP
# define PISCINE_CONTACT_CLASS_HPP


#include <string>

class Contact {

public:

    Contact( void );
    ~Contact( void );

    void            setFirst_name(std::string);
    void            setLast_name(std::string);
    void            setNickname(std::string);
    void            setLogin(std::string);
    void            setAddress(std::string);
    void            setEmail(std::string);
    void            setPhone(std::string);
    void            setBirthday(std::string);
    void            setMeal(std::string);
    void            setUnderwear(std::string);
    void            setSecret(std::string);
    std::string    getFirst_name( void ) const;
    std::string    getLast_name( void ) const;
    std::string    getNickname( void ) const;
    std::string    getLogin( void ) const;
    std::string    getAddress( void ) const;
    std::string    getEmail( void ) const;
    std::string    getPhone( void ) const;
    std::string    getBirthday( void ) const;
    std::string    getMeal( void ) const;
    std::string    getUnderwear( void ) const;
    std::string    getSecret( void ) const;



private:

    std::string _first_name;
    std::string _last_name;
    std::string _nickname;
    std::string _login;
    std::string _address;
    std::string _email;
    std::string _phone;
    std::string _birthday;
    std::string _meal;
    std::string _underwear;
    std::string _secret;


};


#endif //PISCINE_CONTACT_CLASS_HPP
