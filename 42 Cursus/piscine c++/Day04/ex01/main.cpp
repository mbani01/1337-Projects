/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 09:09:01 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:37:35 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Enemy.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "SuperMutant.hpp"

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
    std::cout << *me;
    me->equip(pr);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    me->attack(b);
    std::cout << *me;
    /*------------>My tests<-----------------*/
    std::cout << std::endl;
    Character *mbani = new Character("mouad");
    Enemy *en = new SuperMutant();
    std::cout << en->getHP() << std::endl;
    mbani->attack(en);
    std::cout << en->getHP() << std::endl;
    mbani->equip(pr);
    mbani->attack(en);
    std::cout << en->getHP() << std::endl;
    std::cout << mbani->getAP() << std::endl;
    mbani->recoverAP();
    mbani->recoverAP();
    std::cout << mbani->getAP() << std::endl;
    std::cout << mbani->getName() << std::endl;
    delete mbani;
    delete en;
    delete me;
    return 0;
}