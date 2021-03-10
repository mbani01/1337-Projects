/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:01:22 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:53:50 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Squad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"

int main()
{
    ISpaceMarine* bob = new TacticalMarine;
    ISpaceMarine* jim = new AssaultTerminator;
    ISquad* vlc = new Squad;
    vlc->push(bob);
    vlc->push(jim);
    for (int i = 0; i < vlc->getCount(); ++i)
    {
    ISpaceMarine* cur = vlc->getUnit(i);
    cur->battleCry();
    cur->rangedAttack();
    cur->meleeAttack();
    }

    /*-------------> My tests <-------------*/
    std::cout << std::endl;
    ISpaceMarine* clone = vlc->getUnit(0)->clone();
    clone->rangedAttack();
    clone = vlc->getUnit(1)->clone();
    clone->rangedAttack();
    std::cout << std::endl;
    /*---------------- END -----------------*/
    
    delete vlc;
    return 0;
}