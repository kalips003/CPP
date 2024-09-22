#include <iostream>

#include "PhoneBook.hpp"
#include "Contact.hpp"

# define CLEAR "\e[2J\e[H"

////////////////////////////////////////////////]
//  DEFAULT CONSTRUCTOR
PhoneBook::PhoneBook()  {
	for (int i = 0; i < 8; i++) {
		repertoire[i] = Contact();
	}
	how_many_contact = 0;
}

//  DEFUALT DESTRUCTOR
PhoneBook::~PhoneBook() {
}

void	PhoneBook::pushContact(Contact contact) {
	if (how_many_contact >= 8) {
		for (int i = 1; i < 8; i++)
			repertoire[i - 1] = repertoire[i];
		repertoire[7] = contact;
	}
	else {
		repertoire[how_many_contact] = contact;
		how_many_contact++;
	}
}

void	PhoneBook::addContact() {
	Contact contact;

	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string darkest_secret;
	std::string phone_number;

	std::cout << "Enter the first name: ";
	std::cin >> first_name;
	contact.set_first_name(first_name);

	std::cout << "Enter the last name: ";
	std::cin >> last_name;
	contact.set_last_name(last_name);

	std::cout << "Enter the nickname: ";
	std::cin >> nickname;
	contact.set_nickname(nickname);

	std::cout << "Enter the set_darkest_secret: ";
	std::cin >> darkest_secret;
	contact.set_darkest_secret(darkest_secret);

	std::cout << "Enter the phone number: ";
	std::cin >> phone_number;
	contact.set_phone_number(phone_number);

	if (first_name.empty() || last_name.empty() || nickname.empty() || darkest_secret.empty() || phone_number.empty())
		std::cout << "Invalid Empty Contact!";
	else
		pushContact(contact);
}

void	PhoneBook::searchContact() const {
	std::cout << "   Index |First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (repertoire[i].get_first_name().empty())
			break;
		repertoire[i].printSmallDescription(i + 1);
	}
	std::cout << "Enter the index of the contact to display: ";
	int input_index = -1;
	std::cin >> input_index;
	while (input_index < 1 || input_index > 8)
	{
		std::cout << "Invalid index! Please try again: ";
		std::cin >> input_index;
	}
	repertoire[input_index - 1].printData();
}
