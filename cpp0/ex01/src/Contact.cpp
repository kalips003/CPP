#include "Contact.hpp"

Contact::Contact(int how_many_contact) {
	first_name = ft_print_cat3(C_341, C_434, "first_name", how_many_contact, "Enter the first name", 0b110);
	last_name = ft_print_cat3(C_341, C_434, "last_name", how_many_contact, "Enter the last name", 0b110);
	nickname = ft_print_cat3(C_341, C_434, "nickname", how_many_contact, "Enter the nickname", 0b110);
	darkest_secret = ft_print_cat3(C_341, C_434, "darkest_secret", how_many_contact, "Enter the darkest secret", 0b110);
	phone_number = ft_print_cat3(C_341, C_434, "phone_number", how_many_contact, "Enter the phone number", 0b110);
	
	if (first_name.empty() || last_name.empty() || nickname.empty() || darkest_secret.empty() || phone_number.empty()) {
		std::cout << RED "Invalid Empty Contact!" << std::endl;
		throw 1;
	}
}

/////	SETTER
void  Contact::set_first_name(std::string str) {first_name = str;}
void  Contact::set_last_name(std::string str) {last_name = str;}
void  Contact::set_nickname(std::string str) {nickname = str;}
void  Contact::set_darkest_secret(std::string str) {darkest_secret = str;}
void  Contact::set_phone_number(std::string str) {phone_number = str;}
/////	GETTER
std::string Contact::get_first_name() const {return first_name;}
std::string Contact::get_last_name() const {return last_name;}
std::string Contact::get_nickname() const {return nickname;}
std::string Contact::get_darkest_secret() const {return darkest_secret;}
std::string Contact::get_phone_number() const {return phone_number;}

////////////////////////////////////////////////]
// STATIC HELPER
static std::string printSmall(std::string to_print) {
	return to_print.length() > 10 ? to_print.substr(0, 9) + "." : to_print.substr(0, 10);
}
////////////////////////////////////////////////]
//  OTHER FUNCTIONS
void Contact::printSmallDescription(int index) const {

	std::cout << "\t│        " << index << "│"
				<< std::setw(10) << std::right << printSmall(first_name) << "│"
				<< std::setw(10) << std::right << printSmall(last_name) << "│"
				<< std::setw(10) << std::right << printSmall(nickname) << "│" << std::endl;
}
void Contact::printData() const {

	std::cout << "First Name: " + first_name << std::endl;
	std::cout << "Last Name: " + last_name << std::endl;
	std::cout << "Nickname: " + nickname << std::endl;
	std::cout << "Phone Number: "  + phone_number << std::endl;
	std::cout << "Darkest Secret: " + darkest_secret << std::endl;
}
