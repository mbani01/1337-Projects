/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 08:34:48 by mbani             #+#    #+#             */
/*   Updated: 2021/02/20 10:41:51 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
private:
    std::string _type;
    unsigned int _xp;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &);
    void operator=(const AMateria &);
    std::string const & getType() const;
    void setType(std::string const &);
    unsigned int getXP() const;
    void setXP(unsigned int);
    void incXP();
    virtual AMateria *clone() const = 0;
    virtual void use(ICharacter& target);
    virtual ~AMateria();
};

#endif