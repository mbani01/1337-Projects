/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:04:55 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 10:06:09 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
Cure::Cure():AMateria("cure")
{   
}

Cure::Cure(const Cure &obj)
{
    *this = obj;
}

void Cure::operator=(const Cure &obj)
{
    this->setXP(obj.getXP());
    this->setType(obj.getType());
}

AMateria* Cure::clone() const
{
    AMateria *inst = new Cure();
    return inst;
}

void Cure::use(ICharacter &target)
{
    this->incXP();
    std::cout << "* heals " << target.getName() << "\'s wounds" << std::endl;
}

Cure::~Cure()
{
}
