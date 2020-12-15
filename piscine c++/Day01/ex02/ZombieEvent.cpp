/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 16:01:41 by mbani             #+#    #+#             */
/*   Updated: 2020/04/16 20:29:26 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include<time.h> 
#include "ZombieEvent.hpp"

void ZombieEvent::setZombieType(Zombie *zmb)
{
	static int i;
	srand(time(0));
	i += rand();
	(i%2) == 0 ? zmb->type = "Friendly" : zmb->type = "Savage";
}
Zombie* ZombieEvent::newZombie(std::string name)
{
	Zombie *zmb;
	zmb = new Zombie;
	zmb->name = name;
	setZombieType(zmb);
	return zmb;
}
