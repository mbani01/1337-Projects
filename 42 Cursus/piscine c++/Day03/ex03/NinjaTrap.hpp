/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 00:55:33 by mbani             #+#    #+#             */
/*   Updated: 2020/09/27 01:11:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#ifndef _NINJATRAP_HPP
#define _NINJATRAP_HPP
class NinjaTrap : public ClapTrap
{

public:
	NinjaTrap (std::string );
	~NinjaTrap ();
};

NinjaTrap ::NinjaTrap (std::string name)
{
	Hitpoints = 60;
	Maxhitpoints = 60;
	Energypoints = 120;
	Maxenergypoints = 120;
	Level = 1;
	Name += name;
	Meleeattackdamage = 60;
	Rangedattackdamage = 5;
	Armordamagereduction = 0;
}

NinjaTrap ::~NinjaTrap ()
{
}


#endif