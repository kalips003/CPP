#include <iostream>
#include <limits>

#include "_tools.hpp"

#include "PhoneBook.hpp"
#include "Contact.hpp"

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
	Contact new_contact;
    try { new_contact = Contact(how_many_contact);
    } catch (const int &exit) {
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return;
	}
	pushContact(new_contact);
	// Contact contact(how_many_contact);

	// std::string first_name;
	// std::string last_name;
	// std::string nickname;
	// std::string darkest_secret;
	// std::string phone_number;

	// std::cout << "Enter the first name: " << std::endl;
	// std::cin >> first_name;
	// contact.set_first_name(first_name);

	// std::cout << "Enter the last name: " << std::endl;
	// std::cin >> last_name;
	// contact.set_last_name(last_name);

	// std::cout << "Enter the nickname: " << std::endl;
	// std::cin >> nickname;
	// contact.set_nickname(nickname);

	// std::cout << "Enter the darkest secret: " << std::endl;
	// std::cin >> darkest_secret;
	// contact.set_darkest_secret(darkest_secret);

	// std::cout << "Enter the phone number: " << std::endl;
	// std::cin >> phone_number;
	// contact.set_phone_number(phone_number);
	// contact.set_first_name(ft_print_ccat(C_341, C_434, C_045, how_many_contact, "Enter the first name", 0b110));
	// contact.set_first_name(ft_print_ccat(C_341, C_434, C_045, how_many_contact, "Enter the last name", 0b110));
	// contact.set_first_name(ft_print_ccat(C_341, C_434, C_045, how_many_contact, "Enter the nickname", 0b110));
	// contact.set_first_name(ft_print_ccat(C_341, C_434, C_045, how_many_contact, "Enter the darkest secret", 0b110));
	// contact.set_first_name(ft_print_ccat(C_341, C_434, C_045, how_many_contact, "Enter the phone number", 0b110));
	


	// if (first_name.empty() || last_name.empty() || nickname.empty() || darkest_secret.empty() || phone_number.empty())
	// 	std::cout << "Invalid Empty Contact!" << std::endl;
	// else
	// 	pushContact(contact);
}

void	PhoneBook::searchContact() const {
	ft_print_ccat(C_123, C_021, C_551, how_many_contact, "Contact list:", 0b10);
	std::cout << "   Index |First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "---------|----------|----------|----------|" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (repertoire[i].get_first_name().empty())
			break;
		repertoire[i].printSmallDescription(i + 1);
	}
	std::cout << "---------|----------|----------|----------|" << std::endl;


	int input_index = -1;
	while (true)
	{
		std::cout << "Enter the index of the contact to display: " << std::endl;
		std::cin >> input_index;

		if (std::cin.fail() || input_index < 1 || input_index > 8) {
			std::cin.clear(); // Clear the error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
			std::cout << RED "Invalid index! Please try again." << std::endl;
		} else
			break;
	}

	if (repertoire[input_index - 1].get_first_name().empty())
		std::cout << GREEN "Empty Contact" << std::endl;
	else {
		ft_print_cat(input_index, "Details for requested number:", 0b10);
		repertoire[input_index - 1].printData();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}
