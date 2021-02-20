/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/03 18:16:09 by mbani             #+#    #+#             */
/*   Updated: 2021/01/12 11:10:25 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>

void ZombieHorde::annouce()
{
	int i = 0;
	while(this->Zmb[i].name[0])
	{
	this->Zmb[i].announce();
	i++;
	}
}
void ZombieHorde::create(Zombie &Zmb)
{
	static int i;
	std::string	name;
	char		letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
	'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	srand(time(0));
	for(int j = 0; j < (i%8+3); j++)
	{	
		i += rand() % 26;
		name += letters[i % 26];
	}
	Zmb.name = name;
	(i%2) == 0 ? Zmb.type = "Friendly" : Zmb.type = "Savage";
}
ZombieHorde::ZombieHorde(int N)
{
	int i = 0;
	if (N < 0)
	{
		std::cout<<"ERROR !!!"<<std::endl;
		exit(1);
	}
	this->Zmb = new Zombie[N];
	while(i < N)
	{
		create(this->Zmb[i]);
		i++;
	}
	annouce();
}

ZombieHorde::~ZombieHorde()
{
	delete [] Zmb;
	std::cout<<"all zombies destroyed Braiiiinz HAHAHA";
}