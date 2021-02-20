/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:14:45 by mbani             #+#    #+#             */
/*   Updated: 2021/02/12 17:15:42 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon()
{
    
}

Peon::Peon(std::string name):Victim(name)
{
    std::cout << "Zog zog." << std::endl;
    this->name = name;
}

Peon::Peon(const Peon &obj)
{
    name = obj.name;
}

void Peon::operator=(const Peon &obj)
{
    name = obj.name;
}

Peon::~Peon()
{
    std::cout << "Bleuark..." << std::endl;
}

void Peon::getPolymorphed(void) const
{
    std::cout << this->name << " has been turned into a pink pony!" <<std::endl;
}

                /* Dog class */

dog::dog()
{

}

dog::dog(std::string name):Victim(name)
{
    std::cout << "Bow-wow." << std::endl;
    this->name = name;
}

void dog::operator=(const dog &obj)
{
    name = obj.name;
}

void dog::getPolymorphed(void) const
{
        std::cout << this->name << " has been turned into a pink cat!" <<std::endl;

}

dog::dog(const dog &obj)
{
    name = obj.name;   
}

dog::~dog()
{
    
    std::cout << "Woooooooooe" << std::endl;
}