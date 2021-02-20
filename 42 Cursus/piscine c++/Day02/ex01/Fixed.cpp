/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 0Fixed::bits:24:50 by mbani             #+#    #+#             */
/*   Updated: 2021/02/06 0Fixed::bits:44:22 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <cmath>

Fixed::Fixed()
{
    value = 0;
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &old)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = old;
}
Fixed::Fixed(const int nbr)
{
    std::cout << "Int constructor called" << std::endl;
    this->value = nbr * (1 << Fixed::bits);
}
Fixed::Fixed(const float nbr)
{
    std::cout << "Float constructor called" << std::endl;
    this->value = roundf(nbr * (1 << Fixed::bits)); 
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
void Fixed::operator=(const Fixed &right)
{
    std::cout << "Assignation operator called" << std::endl;
    value = right.value;
}
float Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return value;
}
void Fixed::setRawBits(int const raw)
{
    value = raw;
}
float Fixed::toFloat(void) const
{
    return (float)value / (1 << Fixed::bits);
}
int Fixed::toInt(void) const
{
    return value / (1 << Fixed::bits);
}
std::ostream &operator<<(std::ostream& out,Fixed  const & obj)
{
    out << obj.toFloat();
    return out;
}