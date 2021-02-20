/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 22:58:09 by mbani             #+#    #+#             */
/*   Updated: 2021/01/10 15:12:46 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout<<this->name<<" attacks with his "<<this->wp->getType()<<std::endl;
}
HumanA::HumanA(std::string name1, Weapon &wp_ref)
{
	name += name1;
	wp = &wp_ref;
}

HumanA::~HumanA()
{
}
