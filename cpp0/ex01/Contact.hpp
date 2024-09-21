#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact {
private:
    /////   PRIVATE DATA
    std::string first_name;
    std::string last_name;
    std::string nickname;
    std::string darkest_secret;
    std::string phone_number;


public:
    /////   PUBLIC STANDARD FUNCIONS
    Contact();
    Contact(int value);
    Contact(const Contact& other);
    ~Contact();
    // Contact& operator=(const Contact& other);  // Copy assignment operator

    /////   PUBLIC SETTER GETTER
    void setAttribute(int value);    // Setter
    int getAttribute() const;        // Getter

    // OTHER PUBLIC FUNCTIONS
    void printAttribute() const;

    /////   PUBLIC DATA
    std::string name;

};

#endif