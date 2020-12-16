/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:46:05 by mbani             #+#    #+#             */
/*   Updated: 2020/04/21 22:57:38 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	void setType(std::string str);
	const std::string& getType() const;
	Weapon(std::string he);
	Weapon();
	~Weapon();
};

