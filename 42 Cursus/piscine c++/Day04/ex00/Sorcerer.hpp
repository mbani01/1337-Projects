/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 15:42:50 by mbani             #+#    #+#             */
/*   Updated: 2021/02/12 16:01:07 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Victim.hpp"
#ifndef SORCERER_HPP
#define SORCERER_HPP

class Sorcerer
{
protected:
    std::string name;
    std::string title;
    Sorcerer();
public:
    Sorcerer(std::string name, std::string title);
    Sorcerer(const Sorcerer &);
    std::string getname(void) const;
    std::string gettitle(void) const;
    void polymorph(Victim const &) const;
    void operator=(const Sorcerer &);
    ~Sorcerer();
};

std::ostream& operator<<(std::ostream& out, const Sorcerer &obj);

#endif