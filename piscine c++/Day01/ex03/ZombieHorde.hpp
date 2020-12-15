/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:17:14 by mbani             #+#    #+#             */
/*   Updated: 2020/04/18 16:53:27 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

class ZombieHorde{
	public:
		Zombie *Zmb;
		void annouce();
		void create();
	ZombieHorde(int N);
	~ZombieHorde();
};
void ZombieHorde::annouce()
{
	this->Zmb->announce();
}
void ZombieHorde::create()
{
	static int i;
	std::string	name;
	char		letters[26] = {'a','b','c','d','e','f','g','h','i','j','k','l',
	'm','n','o','p','q','r','s','t','u','v','w','x','y','z'};

	srand(time(0));
	for(int j = 0; j < (i%8+3); j++)
	{	
		i += rand()%26;
		name+= letters[i%26];
	}
	this->Zmb->name = name;
	(i%2) == 0 ? this->Zmb->type = "Friendly" : this->Zmb->type = "Savage";
	// std::cout<<this->Zmb->name<<this->Zmb->type<<std::endl;
	annouce();
}
ZombieHorde::ZombieHorde(int N)
{
	int i=0;
	this->Zmb = new Zombie[N];
	while(i < N)
	{
		create();
		i++;
	}
}

ZombieHorde::~ZombieHorde()
{
	delete [] Zmb;
	std::cout<<"all zombies destroyed Braiiiinz HAHAHA";
}