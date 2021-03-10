/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:30:54 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:32:09 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"
#ifndef POWERFIST_HPP
#define POWERFIST_HPP

class PowerFist : public AWeapon
{
    public:
        PowerFist();
        PowerFist(const PowerFist &);
        void operator=(const PowerFist &);
        void attack() const;
        virtual ~PowerFist();
};


#endif