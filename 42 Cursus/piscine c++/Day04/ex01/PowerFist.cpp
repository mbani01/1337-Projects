/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:40:34 by mbani             #+#    #+#             */
/*   Updated: 2021/02/13 15:40:49 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"


PowerFist::PowerFist():AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(const PowerFist &obj):AWeapon("Power Fist", 8, 50)
{
    name = obj.name;
    damage = obj.damage;
    AP_cost = obj.AP_cost;
}

void PowerFist::operator=(const PowerFist &obj)
{
    name = obj.name;
    damage = obj.damage;
    AP_cost = obj.AP_cost;   
}

void PowerFist::attack() const
{
    std::cout << "* pschhh... SBAM! *" << std::endl;
}

PowerFist::~PowerFist()
{
}
