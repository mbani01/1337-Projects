/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:17:44 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:34:06 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"


Enemy::Enemy()
{
}

Enemy::Enemy(int hp, std::string const & type):hp(hp), type(type)
{
}

Enemy::Enemy(const Enemy &obj)
{
    hp = obj.hp;
    type = obj.type;
}

void Enemy::operator=(const Enemy &obj)
{
    hp = obj.hp;
    type = obj.type;
}

int Enemy::getHP() const
{
    return this->hp;
}

std::string Enemy::getType() const
{
    return this->type;
}

void Enemy::takeDamage(int amount)
{
    if (amount >= 0)
    {
        hp -= amount;
        if (hp < 0)
            hp = 0;
    }
}

Enemy::~Enemy()
{
}
