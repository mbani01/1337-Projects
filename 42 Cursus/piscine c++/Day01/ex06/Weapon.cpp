/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:48:19 by mbani             #+#    #+#             */
/*   Updated: 2020/04/21 23:17:02 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(std::string str)
{
	this->type = str;
}

Weapon::Weapon()
{
}
Weapon::Weapon(std::string he)
{
	setType(he);
}

Weapon::~Weapon()
{
}