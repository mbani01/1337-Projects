/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:56:50 by mbani             #+#    #+#             */
/*   Updated: 2021/02/12 16:08:12 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Sorcerer.hpp"

Sorcerer::Sorcerer()
{

}
Sorcerer::Sorcerer(std::string name, std::string title)
{
    std::cout << name << ", " << title << ", is born!" << std::endl;
    this->name = name;
    this->title = title;
}

Sorcerer::Sorcerer(const Sorcerer &obj)
{
    name = obj.name;
    title = obj.title;
}

std::string Sorcerer::getname(void) const
{
    return this->name;
}

std::string Sorcerer::gettitle(void) const
{
    return this->title;
}

void Sorcerer::operator=(const Sorcerer &obj)
{
    name = obj.name;
    title = obj.title;
}

void Sorcerer::polymorph(Victim const &obj)const
{
    obj.getPolymorphed();
}

Sorcerer::~Sorcerer()
 {
     std::cout << name << ", " << title << ", is dead. Consequences will never be the same!" << std::endl;
 }

std::ostream& operator<<(std::ostream& out, const Sorcerer &obj)
{
    out << "I am " << obj.getname() << ", " << obj.gettitle() << ", and I like ponies!" << std::endl;
    return out;
}

