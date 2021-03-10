/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 16:09:32 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:04:18 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"
#ifndef PEON_HPP
#define PEON_HPP

class Peon : public Victim
{
private:
    Peon();
public:
    Peon(std::string );
    Peon(const Peon &);
    void operator=(const Peon &);
    void getPolymorphed(void) const;
    virtual ~Peon();

};

class dog : public Victim
{
private:
    dog();
public:
    dog(std::string);
    dog(const dog &);
    void operator=(const dog &);
    void getPolymorphed(void) const;
    virtual ~dog();
};




#endif