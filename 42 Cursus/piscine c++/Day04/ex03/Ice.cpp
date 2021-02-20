/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:35:14 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 10:06:27 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"


AMateria* Ice::clone() const
{
    AMateria *inst = new Ice();
    return inst;
}

Ice::Ice(const Ice &obj)
{
    *this = obj;
}

void Ice::operator=(const Ice &obj)
{
    this->setXP(obj.getXP());
    this->setType(obj.getType());
}

void Ice::use(ICharacter &target)
{
    this->incXP();
    std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}

Ice::Ice():AMateria("ice")
{
}

Ice::~Ice()
{
}
