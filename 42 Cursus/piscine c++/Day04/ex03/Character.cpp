/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:05:58 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 11:01:02 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character()
{
}

Character::Character(std::string name)
{
    this->_name = name;
    this->inventory = new AMateria*[4];
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
}

Character::Character(const Character &obj)
{
    *this = obj;
}

void Character::operator=(const Character &obj)
{
    std::cout << "Overload opeartor called " << std::endl;
    for (int i = 0 ; i < 4; i++)
    {
        if (inventory[i])
        {
            delete inventory[i];
            inventory[i] = NULL;
        }
    }
    if (inventory)
    {    
        delete [] inventory;
        inventory = NULL;   
    }
    inventory = NULL;
    this->inventory = new AMateria*[4];
    this->inventory[0] = NULL;
    this->inventory[1] = NULL;
    this->inventory[2] = NULL;
    this->inventory[3] = NULL;
    for(int i = 0; obj.inventory[i] ; i++)
    {
        this->inventory[i] = obj.inventory[i]->clone();
        this->inventory[i]->setType(obj.inventory[i]->getType());
        this->inventory[i]->setXP(obj.inventory[i]->getXP());
    }  
}

void Character::equip(AMateria *m)
{
    for(int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == NULL)
            {
                inventory[i] = m->clone();
                inventory[i]->setXP(m->getXP());
                break;
            }
    }
}

void Character::unequip(int idx)
{
    if (this->inventory[idx])
        this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >=0 && idx <= 3 && this->inventory[idx] != NULL)
        this->inventory[idx]->use(target);
}

std::string const & Character::getName()const
{
    return this->_name;
}

Character::~Character()
{
    for (int i = 0 ; i < 4 ; i++)
    {
        if (this->inventory[i] != NULL)
            {
                delete this->inventory[i];
            }
    }
    if (this->inventory)
        delete [] this->inventory;
    this->inventory = NULL;
}
