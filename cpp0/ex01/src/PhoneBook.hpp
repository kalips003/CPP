#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <limits>
// use: std::numeric_limits<type>::min(); std::numeric_limits<type>::max(); std::numeric_limits<type>::epsilon();

#include "_lib.hpp"
#include "Contact.hpp"

class PhoneBook {
private:
	/////   PRIVATE DATA
	Contact	repertoire[8];

public:
	/////   PUBLIC STANDARD FUNCIONS
	PhoneBook();
	~PhoneBook();

	/////   PUBLIC SETTER GETTER
	void	pushContact(Contact contact);
	void	addContact();
	void	searchContact() const;

	int		how_many_contact;
};

#endif