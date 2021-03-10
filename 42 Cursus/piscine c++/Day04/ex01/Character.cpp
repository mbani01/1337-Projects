/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:03:37 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:31:43 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character(std::string const &name)
{
    this->name = name;
    AP = 40;
    wp = NULL;
}

void Character::recoverAP()
{
    if (AP + 10 > 40)
        AP = 40;
    else
        AP += 10;
}

void Character::equip(AWeapon *wep)
{
    wp = wep;
}

void Character::attack(Enemy *en)
{
    if (wp && AP > 0 && en && en->getHP() > 0)
    {
        AP -= wp->getAPCost();
        std::cout << name << " attacks " << en->getType() << " with a " << wp->getName() << std::endl;
        wp->attack();
        en->takeDamage(wp->getDamage());
        if (en->getHP() <= 0)
        {    
            delete en;
            en = NULL;
        }
    }
}

std::string const Character::getName() const
{
    return this->name;
}

AWeapon* Character::getWeapon() const
{
    return this->wp;
}

int Character::getAP() const 
{
    return this->AP;
}

Character::Character()
{
}

Character::~Character()
{
}

std::ostream& operator<<(std::ostream & out,Character const & obj)
{
    if (obj.getWeapon())
        out << obj.getName() << " has " << obj.getAP() << " AP and wields a " << obj.getWeapon()->getName() << std::endl;
    else
        out << obj.getName() << " has " << obj.getAP() << " AP and is unarmed" << std::endl;
    return out;
}
