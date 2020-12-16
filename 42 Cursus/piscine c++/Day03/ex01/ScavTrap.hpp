/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:40:55 by mbani             #+#    #+#             */
/*   Updated: 2020/09/25 18:43:41 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

class ScavTrap
{
private:
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
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void challengeNewcomer(std::string const & target);
	ScavTrap(std::string name);
	~ScavTrap();
};

#endif