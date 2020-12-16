/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:44:19 by mbani             #+#    #+#             */
/*   Updated: 2020/09/27 00:41:39 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


void ClapTrap::takeDamage(unsigned int amount)
{
	if((Hitpoints - (int)(amount)) + Armordamagereduction < 0)
		Hitpoints = 0;
	else
		Hitpoints = Hitpoints - amount + Armordamagereduction;
	if((Energypoints + Armordamagereduction) < (int)(amount))
		Energypoints = 0;
	else
		Energypoints = Energypoints - amount + Armordamagereduction;
	std::cout<<"\033[1;31mYou are damaged :( !\033[0m HP:"<<Hitpoints<<" Energypoints :"<<Energypoints<<std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if((int)(amount) + Hitpoints > Maxhitpoints)
		Hitpoints = Maxhitpoints;
	else
		Hitpoints += amount;
	if((int)(amount) + Energypoints > Maxenergypoints)
		Energypoints = Maxenergypoints;
	else
		Energypoints += amount;
	std::cout<<"\033[1;32mYou are Repaired :) !\033[0m HP:"<<Hitpoints<<" Energypoints :"<<Energypoints<<std::endl;
}

ClapTrap::ClapTrap()
{
	std::cout<<"Hello World By ClapTrap"<<std::endl;
}


ClapTrap::~ClapTrap()
{
	std::cout<<"OH NO BYEEEE ClapTrap"<<std::endl;
}
