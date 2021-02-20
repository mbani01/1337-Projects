/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:09:01 by mbani             #+#    #+#             */
/*   Updated: 2021/02/15 11:25:33 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"

int main()
{
    Character* me = new Character("me");
    
    std::cout << *me;
    
    Enemy* b = new RadScorpion();
    AWeapon* pr = new PlasmaRifle(); 
    AWeapon* pf = new PowerFist();


    me->equip(pr);
    std::cout << *me;

    me->equip(pf);
    me->attack(b);
    // std::cout << pr->getHP

    std::cout << *me;

    me->equip(pr);
    std::cout << *me;

    me->attack(b);

    std::cout << *me;

    me->attack(b);

    std::cout << *me;

return 0;
}