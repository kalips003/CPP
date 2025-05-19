# ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include "_colors.h"


bool askInfo(const std::string &what, std::string &output);

///////////////////////////////////////////////////////////////////
// (Class)        CONTACTS
///////////////////////////////////////////////////////////////////
class Contact 
{
public:
    Contact( void );
    Contact(const Contact &to_copy);
    Contact &operator=(const Contact &to_copy);
    ~Contact( void );

    Contact(const std::string &first_name, 
        const std::string &last_name, const std::string &nickname,
        const std::string &phone_number, const std::string &darkest_secret);

public:
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string phone_number;
private:
    std::string darkest_secret;

private:

    void            setDarkSecret(const std::string &);
    std::string     getDarkSecret( void ) const;


public:

    void    display_full_contact( void ) const;
    void    display_contact_one_line(int index) const;
    bool    fill_contact( void );
};

#endif
