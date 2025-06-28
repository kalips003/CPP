#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "sstream"
#include "_colors.h"


int ask_index( void );


///////////////////////////////////////////////////////////////////
// (Class)        PHONEBOOK
///////////////////////////////////////////////////////////////////
class PhoneBook
{
private:
   Contact  contacts[8];
   int      num_contact;

public:
    PhoneBook();
    PhoneBook(const PhoneBook &to_copy);
    PhoneBook &operator=(const PhoneBook &to_copy);
    ~PhoneBook();

    bool    ft_add_contact( void );
    void    ft_add_contact(const Contact &new_contact);
    bool    ft_search_contact( void );
    void    ft_empty( void );

};


#endif