/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/15 02:22:13 by mbani             #+#    #+#             */
/*   Updated: 2020/04/16 20:27:09 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include "Zombie.hpp"

class ZombieEvent{
	public:
		void setZombieType(Zombie *zmb);
		Zombie* newZombie(std::string name);
};
