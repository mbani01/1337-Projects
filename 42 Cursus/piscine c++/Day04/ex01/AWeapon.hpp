/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:33:25 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:26:56 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef AWEAPON_HPP
#define AWEAPON_HPP

class AWeapon
{
    protected:
        std::string name;
        int damage;
        int AP_cost;
    private:
        AWeapon();
    public:
        AWeapon(std::string const &name, int apcost, int damage);
        AWeapon(const AWeapon &);
        void operator=(const AWeapon &);
        std::string getName() const;
        int getAPCost() const;
        int getDamage() const;
        virtual void attack() const = 0;
        virtual ~AWeapon();
};

#endif