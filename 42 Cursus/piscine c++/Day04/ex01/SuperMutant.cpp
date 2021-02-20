/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:24 by mbani             #+#    #+#             */
/*   Updated: 2021/02/13 16:39:32 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"


SuperMutant::SuperMutant():Enemy(170, "Super Mutant")
{
    std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &obj):Enemy(170, "Super Mutant")
{
    hp = obj.hp;
    type = obj.type;
}

void SuperMutant::operator=(const SuperMutant &obj)
{
    hp = obj.hp;
    type = obj.type;
}

void SuperMutant::takeDamage(int amount)
{
    amount -= 3;
    if (amount > 0)
    {
        hp -= amount;
    }
}


SuperMutant::~SuperMutant()
{
    std::cout << "Aaargh..." << std::endl;
}
