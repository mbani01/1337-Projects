/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:57:24 by mbani             #+#    #+#             */
/*   Updated: 2021/02/08 12:14:15 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap()
{

}

NinjaTrap::NinjaTrap (std::string name)
{
    std::cout << "NinjaTrap constructor called"<< std::endl;
	Hitpoints = 60;
	Maxhitpoints = 60;
	Energypoints = 120;
	Maxenergypoints = 120;
	Level = 1;
	Name = name;
	Meleeattackdamage = 60;
	Rangedattackdamage = 5;
	Armordamagereduction = 0;
}

NinjaTrap::NinjaTrap(const NinjaTrap &obj)
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

void NinjaTrap::operator=(const NinjaTrap &obj)
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

void NinjaTrap::rangedAttack(std::string const &target)
{
	std::cout<<"Ninja-TP "<<Name<<" attacks "<<target<<" at range, causing "<<Rangedattackdamage<<" points of damage!"<<std::endl;
}
void NinjaTrap::meleeAttack(std::string const & target)
{
	std::cout<<"Ninja-TP "<<Name<<" attacks "<<target<<" at range, causing "<<Meleeattackdamage<<" points of damage!"<<std::endl;
}

void NinjaTrap::ninjaShoebox(const FragTrap &obj) const
{
    (void)obj;
    std::cout << "NinjeShoebox called for a FragTrap !!" << std::endl;
    
}

void NinjaTrap::ninjaShoebox(const ScavTrap &obj) const
{
    (void)obj;
    std::cout << "NinjeShoebox called for a ScavTrap !!" << std::endl;
    
}

void NinjaTrap::ninjaShoebox(const NinjaTrap &obj) const
{
    (void)obj;
    std::cout << "NinjeShoebox called for a NinjaTrap !!" << std::endl;
    
}

NinjaTrap ::~NinjaTrap ()
{
    std::cout<< "NinjaTrap destructor called" << std::endl;
}