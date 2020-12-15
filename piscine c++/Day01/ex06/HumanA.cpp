/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 22:58:09 by mbani             #+#    #+#             */
/*   Updated: 2020/04/21 22:58:47 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void	HumanA::attack()
{
	std::cout<<this->name<<" attacks with his "<<wp->getType()<<std::endl;
}
HumanA::HumanA(std::string name1, Weapon &wp_ref)
{
	name += name1;
	wp = &wp_ref;
}

HumanA::~HumanA()
{
}
