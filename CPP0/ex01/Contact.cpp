#include "Contact.hpp"

#define SUCCESS true
#define FAILURE false

///////////////////////////////////////////////////////////////////////////////]
bool askInfo(const std::string &what, std::string &output) {

    std::string answer;
    std::cout << "Please enter your " << C_301 << what << RESET << ": ";
    if (!std::getline(std::cin, answer)) {
        if (std::cin.eof()) {
            std::cout << std::endl << RED << "\tCTRL+D received, program terminating." << std::endl;
            std::cin.clear();
        }
        else
            std::cout << RED << "Unknown input error, terminating..." << std:: endl;
        return FAILURE;
    }
    output = answer;
    return SUCCESS;
}


///////////////////////////////////////////////////////////////////////////////]
//                     Orthodox Canonical Form
///////////////////////////////////////////////////////////////////////////////]
Contact::Contact( void ) {
}
Contact::Contact(const Contact &to_copy) 
    : first_name(to_copy.first_name), last_name(to_copy.last_name),
    nickname(to_copy.nickname), phone_number(to_copy.phone_number),
    darkest_secret(to_copy.darkest_secret) {
}
Contact::Contact(const std::string &first_name, 
                const std::string &last_name,
                const std::string &nickname,
                const std::string &phone_number,
                const std::string &darkest_secret)
    : first_name(first_name), last_name(last_name), nickname(nickname),
    phone_number(phone_number), darkest_secret(darkest_secret) {
}
Contact &Contact::operator=(const Contact &to_copy) {
    if (this != &to_copy) {
        this->first_name = to_copy.first_name;
        this->last_name = to_copy.last_name;
        this->nickname = to_copy.nickname;
        this->phone_number = to_copy.phone_number;
        this->darkest_secret = to_copy.darkest_secret;
    }
    return *this;
}
Contact::~Contact( void ) {
}


///////////////////////////////////////////////////////////////////////////////]
void    Contact::setDarkSecret(const std::string &secret) {
    this->darkest_secret = secret;}
std::string Contact::getDarkSecret( void ) const {
    return this->darkest_secret;}

///////////////////////////////////////////////////////////////////////////////]
void    Contact::display_contact_one_line(int index) const {

    std::cout << "│" << C_430 << std::setw(10) << index << RESET 
    << "│" << std::setw(10) << (first_name.length() > 10 ? first_name.substr(0, 9) + "." : first_name) 
    << "│" << std::setw(10) << (last_name.length() > 10 ? last_name.substr(0, 9) + "." : last_name) 
    << "│" << std::setw(10) << (nickname.length() > 10 ? nickname.substr(0, 9) + "." : nickname)
    << "│" << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
void    Contact::display_full_contact( void ) const {

    std::cout << std::endl << C_301 << "First Name: " << RESET << first_name << std::endl;
    std::cout << C_301 << "Last Name: " << RESET << last_name << std::endl;
    std::cout << C_301 << "Nickname: " << RESET << nickname << std::endl;
    std::cout << C_301 << "Phone Number: " << RESET << phone_number << std::endl;
    std::cout << C_301 << "Darkest Secret: " << RESET << darkest_secret << std::endl << std::endl;
}

///////////////////////////////////////////////////////////////////////////////]
bool    Contact::fill_contact( void ) {

    if (!askInfo("First Name", this->first_name) || 
        !askInfo("Last Name", this->last_name) || 
        !askInfo("Nickname", this->nickname) || 
        !askInfo("Phone Number", this->phone_number) || 
        !askInfo("Darkest Secret", this->darkest_secret))
        return FAILURE;
    return SUCCESS;
}
