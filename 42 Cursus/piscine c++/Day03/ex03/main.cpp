/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:40:58 by mbani             #+#    #+#             */
/*   Updated: 2021/02/08 12:16:29 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int main()
{
	ScavTrap player2("mamoussa");
	FragTrap player1("mbani");
	NinjaTrap player3("zel-bagh");
	player1.rangedAttack("1st target");
	player1.meleeAttack("2nd target");
	player1.takeDamage(70);
	player1.beRepaired(5);
	player1.vaulthunter_dot_exe("4th target");
	player1.takeDamage(70);
	player1.beRepaired(50);
	player1.vaulthunter_dot_exe("9th target");
	player2.rangedAttack("1st sc");
	player2.meleeAttack("2nd sc");
	player2.takeDamage(109);
	player2.beRepaired(330);
	player2.challengeNewcomer("6th sc");
	player3.meleeAttack("1st");
	player3.ninjaShoebox(player1);
	player3.ninjaShoebox(player2);	
	player3.ninjaShoebox(player3);
}