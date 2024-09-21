#include "Contact.hpp"
#include <iostream>

//  DEFAULT CONSTRUCTOR
Contact::Contact() {
    first_name = "";
    last_name = "";
    nickname = "";
    darkest_secret = "";
    phone_number = "";
}

//  DEFUALT DESTRUCTOR
Contact::~Contact() {
}

/////	SETTER
void  Contact::set_first_name(std::string str) {first_name = str;}
void  Contact::set_last_name(std::string str) {last_name = str;}
void  Contact::set_nickname(std::string str) {nickname = str;}
void  Contact::set_darkest_secret(std::string str) {darkest_secret = str;}
void  Contact::set_phone_number(std::string str) {phone_number = str;}
/////	GETTER
std::string Contact::get_first_name() const {return first_name;}
std::string Contact::get_last_name() const {return last_name;}
std::string Contact::get_nickname() const {return nickname;}
std::string Contact::get_darkest_secret() const {return darkest_secret;}
std::string Contact::get_phone_number() const {return phone_number;}


////////////////////////////////////////////////]
//  OTHER FUNCTIONS
// void Contact::printAttribute() const {
//     std::cout << "The attribute is: " << attribute << std::endl;    
// }