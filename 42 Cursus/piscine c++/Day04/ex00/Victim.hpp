/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:39:48 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 08:59:38 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#ifndef VICTIM_HPP
#define VICTIM_HPP

class Victim
{
protected:
    std::string name;
    Victim();
public:
    Victim(std::string );
    Victim(const Victim &);
    std::string getname(void) const;
    virtual void getPolymorphed() const;
    void operator=(const Victim &);
    virtual ~Victim();
};

std::ostream &operator<<(std::ostream &, const Victim &);

#endif