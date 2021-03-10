/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:23:20 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 12:25:43 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"


PlasmaRifle::PlasmaRifle():AWeapon("Plasma Rifle", 5, 21)
{
}

void PlasmaRifle::attack() const
{
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &obj):AWeapon("Plasma Rifle", 5, 21)
{
   name = obj.name;
   damage = obj.damage;
   AP_cost = obj.AP_cost; 
}

void PlasmaRifle::operator=(const PlasmaRifle &obj)
{
   name = obj.name;
   damage = obj.damage;
   AP_cost = obj.AP_cost;
}

PlasmaRifle::~PlasmaRifle()
{
}