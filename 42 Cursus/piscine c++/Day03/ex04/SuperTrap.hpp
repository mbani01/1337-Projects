/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbani <mbani@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:45:13 by mbani             #+#    #+#             */
/*   Updated: 2021/02/10 17:53:23 by mbani            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERTRAP_HPP
#define SUPERTRAP_HPP

#include "NinjaTrap.hpp"

class SuperTrap : public NinjaTrap, public FragTrap
{

public:
    SuperTrap();
    SuperTrap(std::string);
    ~SuperTrap();
    void	rangedAttack(std::string const &target);
    void	meleeAttack(std::string const & target);
    void	vaulthunter_dot_exe(std::string const & target);
    void    ninjaShoebox(const FragTrap &obj) const;
	void    ninjaShoebox(const ScavTrap &obj) const;
	void    ninjaShoebox(const NinjaTrap &obj) const;
};

#endif