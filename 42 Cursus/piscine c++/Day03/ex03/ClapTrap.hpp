/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:34:43 by mbani             #+#    #+#             */
/*   Updated: 2020/09/26 23:41:31 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef _CLAPTRAP_HPP
#define _CLAPTRAP_HPP
class ClapTrap
{
protected:
	int Hitpoints;
	int Maxhitpoints;
	int Energypoints;
	int Maxenergypoints;
	int Level;
	std::string Name;
	int Meleeattackdamage;
	int Rangedattackdamage;
	int Armordamagereduction;
public:
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	ClapTrap();
	~ClapTrap();
};

#endif