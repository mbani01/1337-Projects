/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 17:37:32 by mbani             #+#    #+#             */
/*   Updated: 2021/02/23 09:58:35 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP
#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    
private:
    AMateria *inv[4];
public:
    MateriaSource();
    MateriaSource(const MateriaSource&);
    void operator=(const MateriaSource&);
    void learnMateria(AMateria*);
    AMateria* createMateria(std::string const &type);
    virtual ~MateriaSource();
};



#endif