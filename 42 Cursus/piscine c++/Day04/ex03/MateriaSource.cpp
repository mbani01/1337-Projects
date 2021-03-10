/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 14:49:49 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 17:25:41 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    inv[0] = NULL;
    inv[1] = NULL;
    inv[2] = NULL;
    inv[3] = NULL; 
}

void MateriaSource::learnMateria(AMateria *obj)
{
    for(int i = 0 ; i < 4; i++)
    {
        if (inv[i] == NULL)
        {
                inv[i] = obj;
                break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
    for(int i = 0; i < 4 ; i++)
    {
        if(inv[i]->getType() == type)
            return inv[i]->clone();
    }
    return 0;
}

MateriaSource::MateriaSource(const MateriaSource &obj)
{
    *this = obj;
}

void MateriaSource::operator=(const MateriaSource &obj)
{
   for(int i = 0; this->inv[0]; i++)
   {
       if (this->inv[i] != NULL)
        {
            delete inv[i];
            inv[i] = NULL;
        }
   }
   for(int i = 0; obj.inv[i]; i++)
   {
       inv[i] = obj.inv[i]->clone();
       this->inv[i]->setType(obj.inv[i]->getType());
       this->inv[i]->setXP(obj.inv[i]->getXP());
   }
}

MateriaSource::~MateriaSource()
{
}