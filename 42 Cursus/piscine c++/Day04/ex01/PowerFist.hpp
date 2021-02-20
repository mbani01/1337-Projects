/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 15:30:54 by mbani             #+#    #+#             */
/*   Updated: 2021/02/15 09:17:08 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "AWeapon.hpp"
#ifndef POWERFIST_HPP
#define POWERFIST_HPP

class PowerFist : public AWeapon
{
private:
    
public:
    PowerFist();
    PowerFist(const PowerFist &);
    void operator=(const PowerFist &);
    void attack() const;
    ~PowerFist();
};


#endif