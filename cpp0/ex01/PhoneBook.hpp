#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <string>

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