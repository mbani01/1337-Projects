/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/16 20:24:14 by mbani             #+#    #+#             */
/*   Updated: 2021/01/03 18:09:24 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieEvent.hpp"

std::string	random_gen()
{
	static		int i;
	std::string	name;
	char		letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
	'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	srand(time(0));
	for(int j = 0; j < (i%8+3); j++)
	{	
		i += rand()%26;
		name+= letters[i%26];
	}
	return name;
}
void	randomChump()
{
	Zombie		*tst;
	ZombieEvent	event;

	srand(time(0));
	tst = event.newZombie(random_gen());
	tst->announce();
	delete tst;
}
int main()
{
	for(int i=0; i < 10;i++)
	randomChump();
}