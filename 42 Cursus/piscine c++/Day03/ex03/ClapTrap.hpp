/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:34:43 by mbani             #+#    #+#             */
/*   Updated: 2021/02/08 10:48:46 by mbani            ###   ########.fr       */
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
	ClapTrap(const ClapTrap &);
	void operator=(const ClapTrap &);
	~ClapTrap();
};

#endif