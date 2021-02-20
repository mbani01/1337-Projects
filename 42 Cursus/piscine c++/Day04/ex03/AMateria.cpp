/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:07:09 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 10:25:10 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
    this->_xp = 0;
}

AMateria::AMateria(std::string const & type)
{
    this->_xp = 0;
    this->_type = type;
}

AMateria::AMateria(const AMateria &obj)
{
    _xp = obj._xp;
}

void AMateria::operator=(const AMateria &obj)
{
    _xp = obj._xp;
}

std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::setType(std::string const &tp)
{
    this->_type = tp;
}

unsigned int AMateria::getXP() const
{
    return this->_xp;
}

void AMateria::setXP(unsigned int amount)
{
    this->_xp = amount;
}

void AMateria::incXP()
{
    this->_xp += 10;
}

void AMateria::use(ICharacter &target)
{
    (void)target;
    this->incXP();
}

AMateria::~AMateria()
{
}

