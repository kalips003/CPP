#include "Contact.hpp"
#include <iostream>
#include <iomanip>

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
struct ContactEntry {
    Contact contact;  // Instance of Contact
    int index;        // Index for the contact
};

static std::string printSmall(std::string to_print) {
return to_print.length() > 10 ? to_print.substr(0, 9) + "." : to_print.substr(0, 10);
}

    std::cout << "Index      | First Name | Last Name  | Nickname" << std::endl;
    "Enter the index of the contact to display: "
    "Invalid index! Please try again."
////////////////////////////////////////////////]
//  OTHER FUNCTIONS

// Index      | First Name | Last Name  | Nickname  
// -------------------------------------------------
// 0          | Alice      | Johnson    | Al        
// 1          | Bob        | Smith      | Bobby     
// 2          | Charlie    | Brown      | Chuck     
// 3          | David      | Wilson     | Dave      
// 4          | Elizabeth   | Taylor     | Lizzy     
// 5          | Jonathan   | Doe        | Jon       
// 6          | Samantha   | Black      | Sam       
// 7          | Christopher | Longname  | Chris...  
void Contact::printSmallDescription(std::string to_print, int index) const {
    std::cout << index << "         |"
                << std::setw(10) << std::right << printSmall(first_name) << "|"
                << std::setw(10) << std::right << printSmall(last_name) << "|"
                << std::setw(10) << std::right << printSmall(nickname) << "|"; 
;}
void Contact::printData() const {
    std::cout << "First Name:"
"Last Name:" Smith
"Nickname:" Bobby
"Phone Number:" 123-456-7890
"Darkest Secret:" I love pineapple on pizza.
"
// First Name: Bob
// Last Name: Smith
// Nickname: Bobby
// Phone Number: 123-456-7890
// Darkest Secret: I love pineapple on pizza.


;}
// void Contact::printAttribute() const {
//     std::cout << "The attribute is: " << attribute << std::endl;    
// }