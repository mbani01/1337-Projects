/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 23:16:00 by mbani             #+#    #+#             */
/*   Updated: 2020/04/21 23:16:31 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nm)
{
	this->name = nm;
}
void	HumanB::setWeapon(Weapon &wp_ref)
{
	wp = &wp_ref;
}
void	HumanB::attack()
{
	std::cout<<this->name<<" attacks with his "<<wp->getType()<<std::endl;
}
HumanB::~HumanB()
{
}
