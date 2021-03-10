/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 15:13:54 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 10:03:17 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ISquad.hpp"
#include "ISpaceMarine.hpp"
#include <iostream>
#include <iterator>
#ifndef SQUAD_HPP
#define SQUAD_HPP

class Squad : public ISquad
{
    private:
        ISpaceMarine** units;
        int size;
    public:
        Squad();
        Squad(const Squad &);
        void operator=(const Squad &);
        int getCount() const;
        ISpaceMarine* getUnit(int) const;
        int push(ISpaceMarine*);
        virtual ~Squad();
};


 #endif