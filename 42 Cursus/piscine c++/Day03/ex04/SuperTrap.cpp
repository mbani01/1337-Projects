/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 10:07:35 by mbani             #+#    #+#             */
/*   Updated: 2021/02/10 17:53:24 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap()
{

}

SuperTrap::SuperTrap(std::string name):FragTrap(name)
{
    Energypoints = 120;
    Maxenergypoints = 120;
    Level = 1;
    Name = name;
    Meleeattackdamage =  60;
}
void SuperTrap::rangedAttack(std::string const &target)
{
    FragTrap::rangedAttack(target);
}

void	SuperTrap::meleeAttack(std::string const & target)
{
	std::cout<<"Ninja-TP "<<Name<<" attacks "<<target<<" at range, causing "<<Meleeattackdamage<<" points of damage!"<<std::endl;   
}

void	SuperTrap::vaulthunter_dot_exe(std::string const & target)
{
    FragTrap::vaulthunter_dot_exe(target);
}

void SuperTrap::ninjaShoebox(const FragTrap &obj) const
{
    (void)obj;
    std::cout << "NinjeShoebox called for a FragTrap !!" << std::endl;
    
}

void SuperTrap::ninjaShoebox(const ScavTrap &obj) const
{
    (void)obj;
    std::cout << "NinjeShoebox called for a ScavTrap !!" << std::endl;
    
}

void SuperTrap::ninjaShoebox(const NinjaTrap &obj) const
{
    (void)obj;
    std::cout << "NinjeShoebox called for a NinjaTrap !!" << std::endl;
    
}

SuperTrap::~SuperTrap()
{
    std::cout << "SuperTrap destructor called" << std::endl;
}
