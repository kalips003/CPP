/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:17:39 by kalipso           #+#    #+#             */
/*   Updated: 2024/09/24 10:30:09 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/PhoneBook.hpp"
#include "src/Contact.hpp"

int main(void) 
{
	PhoneBook phone;
	std::string input;
	while (!std::cin.eof())
	{
		ft_print_cat3(C_322, C_503, C_105, phone.how_many_contact, "The super dupperr phone!", 0b10);
		std::cout << "[ADD | SEARCH | EXIT]: ";
		std::cout.flush();
		if (!std::getline(std::cin, input)) {
			// std::cin.clear();
			continue;;
		}
		if (input == "EXIT" || input == "exit")
			break;
		if (input == "SEARCH" || input == "search")
			phone.searchContact();
		else if (input == "ADD" || input == "add")
			phone.addContact();
	}
	ft_print_catr("Bye byee!", "I hav totally forgotten everything!!", 0b10);
	return 0;
}