/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:57:27 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:12:53 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"
#ifndef PLASMARIFLE_HPP
#define PLASMARIFLE_HPP

class PlasmaRifle :public AWeapon
{
    public:
        PlasmaRifle();
        PlasmaRifle(const PlasmaRifle &);
        void operator=(const PlasmaRifle &);
        void attack() const;
        virtual ~PlasmaRifle();
};

#endif