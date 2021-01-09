/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 02:07:00 by mbani             #+#    #+#             */
/*   Updated: 2021/01/03 18:09:49 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout<<"<"<<this->name<<" ("<<this->type<<") > Braiinz  !!!!"<<std::endl;
}
Zombie::~Zombie(){

	std::cout<<"Zombie "<<this->name<<"is death !!"<<std::endl;
};