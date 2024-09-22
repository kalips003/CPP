/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:17:39 by kalipso           #+#    #+#             */
/*   Updated: 2024/09/22 03:09:50 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
#include <string>


#include "PhoneBook.hpp"
#include "Contact.hpp"

# define CLEAR "\e[2J\e[H"
# define RESET "\e[0m"
# define BLINK "\e[5m"
# define R_BLINK "\e[25m"
/*******************************************************************************
 * 		PRINT CAT RANDOM COLOR
 * bit[1, .] = cls
 * bit[., 1] = stops
******************************************************************************/
void	ft_print_cat(int num, std::string string2, int bit)
{
	// srand(time(NULL));
	// std::string color1 = "\e[38;5;" + std::to_string((rand() % 255 + 1)) + "m";
	// std::string color2 = "\e[38;5;" + std::to_string((rand() % 255 + 1)) + "m";
	// std::string color3 = "\e[38;5;" + std::to_string((rand() % 255 + 1)) + "m";
	// if ((bit >> 1) & 1)
	// 	std::cout << CLEAR;
	// std::cout << color2 << "\t\tにゃ~" << color1 << "\t⠀╱|、\n\
	// \t\t(˚ˎ。7⠀⠀⠀" << color2 << "~ " << num << " ~" + color1 + "\n\
	// \t\t⠀|、˜\\\t\t\t" + color2 + "~" + string2 + "~" + color1 + "\n\
	// \t\t⠀じしˍ)ノ\n" << std::endl;
	// if ((bit >> 0) & 1)
	// {
	// 	std::cout << BLINK + color3 + "\n\t\t>>>  PRISS ENTER TO CONTINUE  <<<\n" + R_BLINK;
	// 	std::getline(std::cin, color1);
	// }
}


int main(void) 
{
	PhoneBook phone;
	std::string input;
	while (1)
	{
		// ft_print_cat(phone.how_many_contact, "The super dupperr phone!", 0b00);
		std::cout << "accepted commands: ADD, SEARCH and EXIT: ";
		std::cin >> input;
		if (input == "EXIT")
			break;
		if (input == "SEARCH")
			phone.searchContact();
		else if (input == "ADD")
			phone.addContact();
	}
	return 0;
}