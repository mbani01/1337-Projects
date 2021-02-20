/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/19 02:47:04 by mbani             #+#    #+#             */
/*   Updated: 2021/01/10 15:07:16 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Brain.hpp"
#include <sstream>

Brain::Brain(){}
Brain::~Brain(){}
std::string	Brain::identify() const
{
	std::stringstream s;
	s<<this;
	return s.str();
}
