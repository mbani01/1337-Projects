/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 12:37:48 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:59:30 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "AMateria.hpp"

class Character : public ICharacter
{
private:
    std::string _name;
    AMateria** inventory;
public:
    Character();
    Character(std::string );
    Character(const Character &);
    void operator=(const Character &);
    std::string const & getName() const;
    void equip(AMateria* m);
    void unequip(int idx);
    void use(int idx, ICharacter& target);
    virtual ~Character();
};

#endif