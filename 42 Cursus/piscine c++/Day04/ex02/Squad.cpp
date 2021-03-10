/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 11:46:27 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 11:36:40 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"



int Squad::getCount() const
{
   return size;
}

ISpaceMarine* Squad::getUnit(int n) const
{
    if (units[n])
        return units[n];
    else
        return NULL;
}

int Squad::push(ISpaceMarine *new_unit)
{
    if (new_unit != NULL)
    {
        int i = 0;
        ISpaceMarine *tmp[size + 1];
        while (i < size)
        {
            tmp[i] = units[i];
            if (units[i] == new_unit)
                return size;
            i++;
        }
        tmp[i] = new_unit;
        delete [] units;
        units = new ISpaceMarine* [size + 2];
        for(int j = 0; j < size + 1 ; j++)
           {
               units[j] = tmp[j];
            }
        units[size + 1] = NULL;
        size++;
    }
    return size;
}

Squad::Squad()
{
    units = new ISpaceMarine*[1];
    units[0] = NULL;
    size = 0;
}

Squad::Squad(const Squad &obj)
{
    *this = obj;
}

void Squad::operator=(const Squad &obj)
{
    for(int i = 0 ; i < size; i++)
    {
        delete units[i];
        units[i] = NULL;    
    }
    if (units)
    {
        delete [] units;
        units = NULL;
    }
    units = new ISpaceMarine*[obj.size + 1];
    for(int i = 0; i < obj.size; i++)
    {
        units[i] = obj.units[i]->clone();
    }
    units[size] = NULL;
}

Squad::~Squad()
{
    for(int i = 0 ; i < size; i++)
    {
        delete units[i];
        units[i] = NULL;    
    }
    if (units)
    {
        delete [] units;
        units = NULL;
    }
}