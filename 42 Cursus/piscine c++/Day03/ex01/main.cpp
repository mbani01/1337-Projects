/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:40:58 by mbani             #+#    #+#             */
/*   Updated: 2021/02/07 18:27:12 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	ScavTrap player2("mamoussa");
	FragTrap player1("mbani");
	player1.rangedAttack("1st target");
	player1.meleeAttack("2nd target");
	player1.takeDamage(70);
	player1.beRepaired(5);
	player1.vaulthunter_dot_exe("4th target");
	player1.vaulthunter_dot_exe("5th target");
	player1.vaulthunter_dot_exe("6th target");
	player1.vaulthunter_dot_exe("7th target");
	player1.vaulthunter_dot_exe("8th target");
	player1.takeDamage(70);
	player1.beRepaired(50);
	player1.vaulthunter_dot_exe("9th target");
	player2.rangedAttack("1st sc");
	player2.meleeAttack("2nd sc");
	player2.takeDamage(109);
	player2.beRepaired(330);
	player2.challengeNewcomer("3rd sc");
	player2.challengeNewcomer("4th sc");
	player2.challengeNewcomer("5th sc");
	player2.challengeNewcomer("6th sc");
}