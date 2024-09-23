/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:17:39 by kalipso           #+#    #+#             */
/*   Updated: 2024/09/23 06:48:41 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#include "_tools.hpp"

#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void) 
{
	PhoneBook phone;
	std::string input;
	while (1)
	{
		ft_print_ccat(C_322, C_503, C_105, phone.how_many_contact, "The super dupperr phone!", 0b10);
		std::cout << "[ADD | SEARCH | EXIT]: ";
		std::cout.flush();
		std::getline(std::cin, input);
		if (input == "EXIT" || input == "exit")
			break;
		if (input == "SEARCH" || input == "search")
			phone.searchContact();
		else if (input == "ADD" || input == "add")
			phone.addContact();
	}
	ft_print_ccat(C_341, C_434, C_045, phone.how_many_contact, "Bye byee!", 0b10);
	return 0;
}