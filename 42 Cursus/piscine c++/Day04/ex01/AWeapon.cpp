/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:56:04 by mbani             #+#    #+#             */
/*   Updated: 2021/02/13 14:56:20 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon()
{
}

AWeapon::AWeapon(std::string const &name, int apcost, int damage):name(name), AP_cost(apcost), damage(damage)
{
    
}

AWeapon::AWeapon(const AWeapon &obj)
{
    name = obj.name;
    damage = obj.damage;
    AP_cost = obj.AP_cost;
}

void AWeapon::operator=(const AWeapon &obj)
{
    name = obj.name;
    damage = obj.damage;
    AP_cost = obj.AP_cost;
}

std::string AWeapon::getName() const
{
    return this->name;
}

int AWeapon::getAPCost() const
{
    return this->AP_cost;
}

int AWeapon::getDamage() const
{
    return this->damage;
}

AWeapon::~AWeapon()
{
}
