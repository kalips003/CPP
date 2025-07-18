/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalipso <kalipso@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:17:39 by kalipso           #+#    #+#             */
/*   Updated: 2024/09/25 14:15:50 by kalipso          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
	{
		Weapon club = Weapon(C_323 "crude spiked club" RESET);

		HumanA bob(C_410 "Bob" RESET, club);
		bob.attack();
		club.setType(C_414 "some other type of club" RESET);
		bob.attack();
	}
	
	std::cout << std::endl;
	
	{
		Weapon club = Weapon(C_323 "crude spiked club" RESET);

		HumanB jim(C_014 "Jim" RESET);
		jim.attack();
		jim.setWeapon(club);
		jim.attack();
		club.setType(C_414 "some other type of club" RESET);
		jim.attack();
	}

return 0;
}