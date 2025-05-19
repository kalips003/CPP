#include "PhoneBook.hpp"

///////////////////////////////////////////////////////////////////////////////]
int ask_index( void ) {

// (recover input, check if correct, return -1 on error)
std::string answer;
    
    std::cout << "Please enter the index of the contact to display: ";
    if (!std::getline(std::cin, answer)) {
        if (std::cin.eof()) {
            std::cout << std::endl << RED << "\tCTRL+D received, program terminating." << std::endl;
            std::cin.clear();
        }
        else
            std::cout << RED << "Unknown input error, terminating..." << std:: endl;
        return -1;
    }

// (recover int from input stored in string, return the index, 0 on error)
std::istringstream  iss(answer);
int                 rtrn;
char                reste;

    iss >> rtrn;
    if (iss.fail() || rtrn > 8 || rtrn < 1 || iss >> reste) {
        std::cout << "Invalid index" << std::endl;
        return 0;
    }

    return rtrn;
}

///////////////////////////////////////////////////////////////////////////////]
//                     Orthodox Canonical Form
///////////////////////////////////////////////////////////////////////////////]
PhoneBook::PhoneBook( void ) : num_contact(0) {
}
PhoneBook::PhoneBook(const PhoneBook &to_copy) 
    : num_contact(to_copy.num_contact)
{
    for (int i = 0; i < 8; i++)
        this->contacts[i] = to_copy.contacts[i];
}
PhoneBook &PhoneBook::operator=(const PhoneBook &to_copy) {
    if (this != &to_copy) {
        for (int i = 0; i < 8; i++)
            this->contacts[i] = to_copy.contacts[i];
        this->num_contact = to_copy.num_contact;
    }
    return *this;
}
PhoneBook::~PhoneBook( void ) {
}

///////////////////////////////////////////////////////////////////////////////]
// add contact to PhoneBook, prompt user to fill it
bool    PhoneBook::ft_add_contact( void ) {

    bool input;

    if (this->num_contact < 8)
        input = this->contacts[this->num_contact++].fill_contact();
    else {
        for (int i = 1; i < 8; i++)
            this->contacts[i - 1] = this->contacts[i];
        input = this->contacts[7].fill_contact();
    }
    return input;
}
///////////////////////////////////////////////////////////////////////////////]
// add already filled contact to PhoneBook
void    PhoneBook::ft_add_contact(const Contact &new_contact) {

    if (this->num_contact < 8)
        this->contacts[this->num_contact++] = new_contact;
    else {
        for (int i = 1; i < 8; i++)
            this->contacts[i - 1] = this->contacts[i];
        this->contacts[7] = new_contact;
    }
}

///////////////////////////////////////////////////////////////////////////////]
bool    PhoneBook::ft_search_contact( void ) {
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│  "<<C_301<<"Index"<<RESET<<"   │"<<C_301<<"First name"<<RESET<<"│ "<<C_301<<"Last name"<<RESET<<"│ "<<C_301<<"Surname"<<RESET<<"  │" << std::endl;
    std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;

    for (int i = 0; i < num_contact; i++)
        contacts[i].display_contact_one_line(i + 1);

    std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
    std::cout << std::endl;

    int index = ask_index();
    if (index == -1)
        return false;
    if (index > 0 && index <= num_contact)
        contacts[index-1].display_full_contact();
    return true;
}

///////////////////////////////////////////////////////////////////////////////]
void    PhoneBook::ft_empty( void ) {
    num_contact = 0;
}


