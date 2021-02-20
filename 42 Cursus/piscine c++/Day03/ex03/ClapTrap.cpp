/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 23:44:19 by mbani             #+#    #+#             */
/*   Updated: 2021/02/08 10:50:08 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


void ClapTrap::takeDamage(unsigned int amount)
{
	if((Hitpoints - (int)amount) + Armordamagereduction < 0)
		Hitpoints = 0;
	else if ((Hitpoints - (int)amount) + Armordamagereduction > 100)
		Hitpoints = 100;
	else
		Hitpoints = Hitpoints - (int)amount + Armordamagereduction;
	std::cout<<"\033[1;31mYou are damaged :( !!\033[0m, HP:"<<Hitpoints<<std::endl;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if((int)(amount) + Hitpoints > Maxhitpoints)
		Hitpoints = Maxhitpoints;
	else
		Hitpoints += (int)amount;
	if((int)(amount) + Energypoints > Maxenergypoints)
		Energypoints = Maxenergypoints;
	else
		Energypoints += amount;
	std::cout<<"\033[1;32mYou are Repaired :) !\033[0m HP:"<<Hitpoints<<" Energypoints :"<<Energypoints<<std::endl;
}

ClapTrap::ClapTrap()
{
	std::cout<<"Hello World By ClapTrap (ClapTrap Constructor)"<<std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj)
{
	Hitpoints = obj.Hitpoints;
	Maxhitpoints = obj.Maxhitpoints;
	Energypoints = obj.Energypoints;
	Maxenergypoints = obj.Maxenergypoints;
	Level = obj.Level;
	Name = obj.Name;
	Meleeattackdamage = obj.Meleeattackdamage;
	Rangedattackdamage = obj.Rangedattackdamage;
	Armordamagereduction = obj.Armordamagereduction;	
}

void ClapTrap::operator=(const ClapTrap &obj)
{
	Hitpoints = obj.Hitpoints;
	Maxhitpoints = obj.Maxhitpoints;
	Energypoints = obj.Energypoints;
	Maxenergypoints = obj.Maxenergypoints;
	Level = obj.Level;
	Name = obj.Name;
	Meleeattackdamage = obj.Meleeattackdamage;
	Rangedattackdamage = obj.Rangedattackdamage;
	Armordamagereduction = obj.Armordamagereduction;
}

ClapTrap::~ClapTrap()
{
	std::cout<<"OH NO BYEEEE ClapTrap (ClapTrap Destructor)"<<std::endl;
}
