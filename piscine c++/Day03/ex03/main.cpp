/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:40:58 by mbani             #+#    #+#             */
/*   Updated: 2020/09/26 23:44:58 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
	srand(time(0));
	FragTrap tst("mouad");
	tst.rangedAttack("anass");
	tst.meleeAttack("mouad");
	tst.takeDamage(rand()%100);
	tst.beRepaired(rand()%100);
	tst.vaulthunter_dot_exe("anass");
	ScavTrap tst1("anass");
	tst1.rangedAttack("mouad");
	tst1.meleeAttack("mouad");
	tst1.takeDamage(rand()%100);
	tst1.beRepaired(rand()%100);
	tst1.challengeNewcomer("anass");
	// // tst.vaulthunter_dot_exe("anass");
	// // tst.vaulthunter_dot_exe("anass");
	// // tst.takeDamage(rand()%100);
	// // tst.vaulthunter_dot_exe("anass");
	// tst1.challengeNewcomer("anass");
	// tst.vaulthunter_dot_exe("anass");

}