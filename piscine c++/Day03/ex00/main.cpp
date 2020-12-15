/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 23:40:58 by mbani             #+#    #+#             */
/*   Updated: 2020/08/22 16:17:01 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "FragTrap.hpp"

int main()
{
	srand(time(0));
	FragTrap tst("mouad");
	FragTrap tst1("anass");
	tst.rangedAttack("anass");
	tst.meleeAttack("anass");
	tst.takeDamage(rand()%100);
	// tst.beRepaired(rand()%100);
	tst1.vaulthunter_dot_exe("anass");
	tst.vaulthunter_dot_exe("anass");
	tst.vaulthunter_dot_exe("anass");
	// tst.takeDamage(rand()%100);
	tst.vaulthunter_dot_exe("anass");
	tst.vaulthunter_dot_exe("anass");
	tst1.vaulthunter_dot_exe("anass");
	tst.beRepaired(rand()%100);
	tst.vaulthunter_dot_exe("anass");

}