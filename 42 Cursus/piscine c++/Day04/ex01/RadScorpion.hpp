/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:39:56 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:32:51 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"
#ifndef RADSCORPION_HPP
#define RADSCORPION_HPP

class RadScorpion : public Enemy
{
private:
public:
    RadScorpion();
    RadScorpion(const RadScorpion &);
    void operator=(const RadScorpion &);
    virtual ~RadScorpion();
};

#endif