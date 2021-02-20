/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 11:27:05 by mbani             #+#    #+#             */
/*   Updated: 2021/02/12 16:39:14 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim()
{
    
}

Victim::Victim(std::string name)
{
    std::cout << "Some random victim called " << name << " just appeared!" << std::endl;
    this->name = name;
}

Victim::~Victim()
{
    std::cout << "Victim " << this->name << " just died for no apparent reason!" << std::endl;
}

std::string Victim::getname(void) const
{
    return this->name;
}

void Victim::getPolymorphed()const
{
    std::cout << this->name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream &operator<<(std::ostream & out, const Victim & obj)
{
    out << "I'm " << obj.getname() << " and I like otters!" << std::endl;
    return out;
}
