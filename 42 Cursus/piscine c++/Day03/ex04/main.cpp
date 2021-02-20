/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:40:58 by mbani             #+#    #+#             */
/*   Updated: 2021/02/12 08:20:39 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "SuperTrap.hpp"

int main()
{
	FragTrap Frag("asfe");
	ScavTrap Scav("aefd");
	NinjaTrap Ninja("AFWe");
	Frag.takeDamage(10);
	std::cout << "SuperTrap will be created" << std::endl;
	SuperTrap mbani("Asdf");
	Frag.beRepaired(50);
	mbani.rangedAttack("FragTrap");//FragTrap member
	Frag.takeDamage(10);
	mbani.meleeAttack("NinjaTrap");//NinjaTrap member
	mbani.vaulthunter_dot_exe("Frag");
	Frag.beRepaired(50);
	Frag.takeDamage(10);
	mbani.ninjaShoebox(Frag);
	mbani.ninjaShoebox(Scav);
	Frag.beRepaired(50);
	Frag.takeDamage(10);
	mbani.ninjaShoebox(Ninja);

}