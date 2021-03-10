/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/14 17:21:04 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 14:28:23 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

class Character
{

private:
    Character();
    std::string name;
    int AP;
    AWeapon *wp;
public:
    Character(std::string const & name);
    Character(const Character &);
    void operator=(const Character &);
    ~Character();
    void recoverAP();
    void equip(AWeapon*);
    void attack(Enemy*);
    AWeapon* getWeapon() const;
    int getAP() const;
    std::string const getName() const;
};

std::ostream& operator<<(std::ostream &, Character const &);

#endif