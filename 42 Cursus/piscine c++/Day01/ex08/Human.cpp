/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/27 23:05:29 by mbani             #+#    #+#             */
/*   Updated: 2021/01/11 18:03:29 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Human.hpp"

void Human::meleeAttack(std::string const & target)
{
	std::cout<<"meleeAttack called \nThe target is: "<<target<<std::endl;
}

void Human::rangedAttack(std::string const & target)
{
	std::cout<<"rangedAttack called \nThe target is: "<<target<<std::endl;
}

void Human::intimidatingShout(std::string const & target)
{
	std::cout<<"intimidatingShout called \nThe target is: "<<target<<std::endl;
}

void Human::action(std::string const & action_name, std::string const & target)
{
	void (Human::*fptr[3])	(std::string const & target);
	std::string actions[3]={"meleeAttack", "rangedAttack", "intimidatingShout"};
	
	fptr[0] = &Human::meleeAttack;
	fptr[1] = &Human::rangedAttack;
	fptr[2] = &Human::intimidatingShout;
	for(int i = 0; i < 3; i++)
		if(actions[i].compare(action_name) == 0)
		{
			(this->*fptr[i])(target);
			break;
		}
}
