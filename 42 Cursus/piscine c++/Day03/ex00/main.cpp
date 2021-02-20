/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:40:58 by mbani             #+#    #+#             */
/*   Updated: 2021/02/06 15:31:42 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main()
{
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
	player1.vaulthunter_dot_exe("8th target");
	player1.takeDamage(70);
	player1.beRepaired(0);
	player1.vaulthunter_dot_exe("9th target");
}