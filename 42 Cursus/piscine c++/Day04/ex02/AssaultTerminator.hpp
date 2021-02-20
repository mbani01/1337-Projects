/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 15:35:04 by mbani             #+#    #+#             */
/*   Updated: 2021/02/16 15:45:36 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISpaceMarine.hpp"
#ifndef ASSAULTTERMINATOR_HPP
#define ASSAULTTERMINATOR_HPP

class AssaultTerminator : public ISpaceMarine
{
public:
    AssaultTerminator();
    ISpaceMarine* clone() const;
    void battleCry() const;
    void rangedAttack() const;
    void meleeAttack() const;
    ~AssaultTerminator();
};

#endif