/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 17:17:14 by mbani             #+#    #+#             */
/*   Updated: 2021/01/09 17:03:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

class ZombieHorde{
	private:
		Zombie *Zmb;
	public:
		void annouce();
		void create(Zombie &Zmb);
	ZombieHorde(int N);
	~ZombieHorde();
};
