/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 22:59:08 by mbani             #+#    #+#             */
/*   Updated: 2020/04/21 23:16:22 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

class HumanB
{
private:
	std::string name;
	Weapon *wp;
public:
	HumanB(std::string);
	void attack();
	void setWeapon(Weapon &);
	~HumanB();
};
