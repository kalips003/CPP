#include "PhoneBook.hpp"

///////////////////////////////////////////////////////////////////////////////]
// 								- BASE - 
///////////////////////////////////////////////////////////////////////////////]
PhoneBook::PhoneBook()  {
	for (int i = 0; i < 8; i++) {
		repertoire[i] = Contact();
	}
	how_many_contact = 0;
}

//  DEFUALT DESTRUCTOR
PhoneBook::~PhoneBook() {
}

///////////////////////////////////////////////////////////////////////////////]
// 								PUSH CONTACT
///////////////////////////////////////////////////////////////////////////////]
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

///////////////////////////////////////////////////////////////////////////////]
// 								ADD CONTACT
///////////////////////////////////////////////////////////////////////////////]
void	PhoneBook::addContact() {
	Contact new_contact;
	try { Contact new_contact = Contact(how_many_contact);
	} catch (const int &exit) { return; }
	pushContact(new_contact);
}

///////////////////////////////////////////////////////////////////////////////]
// 								SEARCH CONTACT
///////////////////////////////////////////////////////////////////////////////]
void	PhoneBook::searchContact() const {

	if (repertoire[0].get_first_name().empty()) {
		std::cout << C_115 "Empty Contact List" << std::endl;
		for (int i = 0; i > 8; i++)
			std::cout << i << " ) name: " << repertoire[0].get_first_name() << std::endl;
		ft_print_cat();
		return;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - -]
// Print the contact list
	ft_print_cat3(C_123, C_021, C_551, how_many_contact, "Contact list:", 0b10);
	std::cout << "\t┌─────────┬──────────┬──────────┬──────────┐" << std::endl;
	std::cout << "\t│   Index │First Name│ Last Name│  Nickname│" << std::endl;
	std::cout << "\t├─────────┼──────────┼──────────┼──────────┤" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		if (repertoire[i].get_first_name().empty())
			break;
		repertoire[i].printSmallDescription(i + 1);
	}
	std::cout << "\t└─────────┴──────────┴──────────┴──────────┘\n" << std::endl;

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - -]
// check if input is correct
	std::string input;
	int number_index;
	int	r = 0;
	std::cout << "Enter the index of the contact to display [1-8]: ";
	while (true && ++r < 10)
	{
		if (r == 5) {
			ft_print_cat3(C_511, C_402, C_520, "..........", "Do you have some issues?", 0b11);
			return;
		}
		if (!std::getline(std::cin, input)) {
			std::cin.clear();
			return;
		}
		std::istringstream stoi(input);
		if (stoi >> number_index && number_index > 0 && number_index < 9)
			break;
		std::cout << "Invalid input! Please enter a valid integer between [1-8]: " << std::endl;
	}

// - - - - - - - - - - - - - - - - - - - - - - - - - - - -  - - - - - - - - - -]
// the number is correct, does contact exist?
// print details of contact, wait
	if (repertoire[number_index - 1].get_first_name().empty() || repertoire[0].get_first_name().empty()) {
		std::cout << C_115 "Empty Contact" << std::endl;
		ft_print_cat();
	} else {
		std::string c = ft_print_catr("Details for requested number:", "Press Enter to go back to main screen", 0b10);
		repertoire[number_index - 1].printData();
		ft_print_cat();
	}
}
