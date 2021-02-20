/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:23:04 by mbani             #+#    #+#             */
/*   Updated: 2021/02/15 09:17:22 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Enemy.hpp"
#ifndef SUPERMUTANT_HPP
#define SUPERMUTANT_HPP

class SuperMutant : public Enemy
{
private:
    
public:
    SuperMutant();
    SuperMutant(const SuperMutant &);
    void operator=(const SuperMutant &);
    void takeDamage(int );
    ~SuperMutant();
};


#endif