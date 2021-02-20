/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 20:01:21 by mbani             #+#    #+#             */
/*   Updated: 2021/02/08 10:45:35 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap()
{
	
}

FragTrap::FragTrap(std::string name)
{
	std::cout<<"Success! My spell to make you want to hang out with me worked! (FragTrap Constructor)"<<std::endl;
	Hitpoints = 100;
	Maxhitpoints = 100;
	Energypoints = 100;
	Maxenergypoints = 100;
	Level = 1;
	Name = name;
	Meleeattackdamage = 30;
	Rangedattackdamage = 20;
	Armordamagereduction = 5;
}

FragTrap::FragTrap(const FragTrap &obj)
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

void FragTrap::operator=(const FragTrap &obj)
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

FragTrap::~FragTrap()
{
	std::cout<<"Stay a while, and listen. Oh god, please -- PLEASE! -- stay a while. (FragTrap Destructor)"<<std::endl;
}
void FragTrap::rangedAttack(std::string const &target)
{
	std::cout<<"FR4G-TP "<<Name<<" attacks "<<target<<" at range, causing "<<Rangedattackdamage<<" points of damage!"<<std::endl;
}
void FragTrap::meleeAttack(std::string const & target)
{
	std::cout<<"FR4G-TP "<<Name<<" attacks "<<target<<" at range, causing "<<Meleeattackdamage<<" points of damage!"<<std::endl;
}
void FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	
	char attacks[5][10] = {"Kido ", "Power ", "Blabla " , "Baby ", "Shity "};
	srand(time(0));
	static int i;
	i += rand();
	if(Energypoints < 25)
		std::cout<<"Out of energy !!"<<std::endl;
	else
	{
		Energypoints -=25;
		std::cout<<"FR4G-TP "<<Name<<" attacks "<<target<<" at range, causing "<<abs(i)%4*10+5<<" points of damage!"<<"("<<attacks[abs(i)%4]<<"attack)"<<std::endl;
	}
}