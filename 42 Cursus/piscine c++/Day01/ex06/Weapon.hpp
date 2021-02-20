/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/21 16:46:05 by mbani             #+#    #+#             */
/*   Updated: 2021/01/10 15:09:21 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Weapon
{
private:
	std::string type;
public:
	const std::string& getType() const;
	void setType(std::string str);
	Weapon(std::string he);
	Weapon();
	~Weapon();
};

