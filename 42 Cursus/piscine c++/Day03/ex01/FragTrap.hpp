/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/21 16:23:54 by mbani             #+#    #+#             */
/*   Updated: 2020/08/25 15:26:30 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef FRAGTRAP_HPP
#define	FRAGTRAP_HPP

class FragTrap
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
	void vaulthunter_dot_exe(std::string const & target);
	FragTrap(std::string );
	~FragTrap();
};



#endif
